// Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
// Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
#include "debug.h"
#include <QLabel>
#include <QMessageBox>
#include <QTimer>
#include "aboutme.h"
#include <chrono>
#include "stdio.h"
#include <QVector>
#include <QListView>
#include <QStringListModel>
#include <QEventLoop>
#include <QColor>
#include <QTableWidgetItem>
static constexpr std::chrono::seconds kWriteTimeout = std::chrono::seconds{5};

//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
//! [0]
    m_status(new QLabel),
    m_console(new Console),
    m_settings(new SettingsDialog(this)),
    m_timer(new QTimer(this)),
m_clear_timer(new QTimer(this)),
//! [1]
    m_serial(new QSerialPort(this)),
    m_debug(new debug(this)),
    m_monitor(new monitor(this))

{
//! [1]
    m_ui->setupUi(this);
    m_console->setEnabled(false);
    //setCentralWidget(m_console);
    m_ui->terminalWidget=m_console;

    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionQuit->setEnabled(true);
    m_ui->actionConfigure->setEnabled(true);

    m_ui->statusBar->addWidget(m_status);

    m_ui->actionDebug->setEnabled(false);
    initActionsConnections();

    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::handleWriteTimeout);
    m_timer->setSingleShot(true);
    /**User Codes****/
    m_ui->actionTerminal->setEnabled(false);
    m_ui->actionClear->setEnabled(false);
    m_ui->actionDebug->setEnabled(false);
    m_debug->setSerial(m_serial);
    //
    m_ui->Statuslabel->setText("---");
    m_ui->ModeLabel->setText("---");
    m_ui->groupBox->setEnabled(false);
    m_ui->tabWidget->setEnabled(false);

    /*******/
//! [2]
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    connect(m_serial, &QSerialPort::bytesWritten, this, &MainWindow::handleBytesWritten);
//! [2]
    connect(m_console, &Console::getData, this, &MainWindow::writeData);

    //automatically clear terminal buff every 10 seconds
    connect(m_clear_timer, &QTimer::timeout,  m_console, &Console::clear);
    m_clear_timer->start(10000);
    //test code
    QTableWidgetItem *item = new QTableWidgetItem("Cell Text");
     m_ui->tableWidget->setRowCount(2);
     m_ui->tableWidget->setColumnCount(2);
    // Set the background color of the item
    item->setBackground(Qt::yellow); // Change "Qt::red" to the desired color

    // Set the item for the desired cell in the table
    m_ui->tableWidget->setItem(1, 1, item);


//!

}
//! [3]

MainWindow::~MainWindow()
{
    delete m_settings;
    delete m_ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    const SettingsDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        m_console->setEnabled(true);
        m_console->setLocalEchoEnabled(p.localEchoEnabled);
        m_ui->actionConnect->setEnabled(false);
        m_ui->actionDisconnect->setEnabled(true);
        m_ui->actionConfigure->setEnabled(false);
        m_ui->actionTerminal->setEnabled(true);
        m_ui->actionClear->setEnabled(true);
         m_ui->actionDebug->setEnabled(true);
        m_ui->groupBox->setEnabled(true);
        m_ui->tabWidget->setEnabled(true);



        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name, p.stringBaudRate, p.stringDataBits,
                               p.stringParity, p.stringStopBits, p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    m_console->setEnabled(false);
    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionConfigure->setEnabled(true);
    m_ui->actionTerminal->setEnabled(false);
    m_ui->actionClear->setEnabled(false);
    m_ui->groupBox->setEnabled(false);
    m_ui->actionDebug->setEnabled(true);
    m_ui->tabWidget->setEnabled(false);
    m_ui->actionDebug->setEnabled(false);
    showStatusMessage(tr("Disconnected"));
}
//! [5]

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Serial Terminal"),
                       tr("The <b>Serial Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

//! [6]
void MainWindow::writeData(const QByteArray &data)
{
    const qint64 written = m_serial->write(data);
    if (written == data.size()) {
        m_bytesToWrite += written;
        m_timer->start(kWriteTimeout);
    } else {
        const QString error = tr("Failed to write all data to port %1.\n"
                                 "Error: %2").arg(m_serial->portName(),
                                                  m_serial->errorString());
        showWriteError(error);
    }
}
//! [6]

//! [7]
void MainWindow::readData()
{
    const QByteArray data = m_serial->readAll();
    m_console->putData(data);
    m_debug->readData(data);
    //read pceoss
    auto flag_bit = data[0];
    //**report process**//
    if(flag_bit == 'r'){

        auto str = data.data();
        char mode;
        sscanf(str,"r$%c$",&mode);


        //even mode
        if(mode == 'e'){
            m_ui->Statuslabel->setText("Connected");
            m_ui->ModeLabel->setText("Even Mode");
            m_ui->stopButton->setEnabled(true);
        }

        //stopped
        if(mode == 'p'){
            m_ui->Statuslabel->setText("Connected");
            m_ui->ModeLabel->setText("Stopped");
            m_ui->stopButton->setEnabled(false);
        }

        //gust mode
        if(mode == 'g'){
            m_ui->Statuslabel->setText("Connected");
            m_ui->ModeLabel->setText("Gust");
            m_ui->stopButton->setEnabled(true);
        }

        //sheer mode
        if(mode == 's'){
            m_ui->Statuslabel->setText("Connected");
            m_ui->ModeLabel->setText("Sheer");
            m_ui->stopButton->setEnabled(true);
        }

    }

    //report missing device
    if(flag_bit=='q'){
        //handle it to debug
    }



}
//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}
//! [8]

//! [9]
void MainWindow::handleBytesWritten(qint64 bytes)
{
    m_bytesToWrite -= bytes;
    if (m_bytesToWrite == 0)
        m_timer->stop();
}
//! [9]

void MainWindow::handleWriteTimeout()
{
    const QString error = tr("Write operation timed out for port %1.\n"
                             "Error: %2").arg(m_serial->portName(),
                                              m_serial->errorString());
    showWriteError(error);
}

void MainWindow::handleTerminal()
{
    m_console->show();
}

void MainWindow::initActionsConnections()
{
    connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
    connect(m_ui->actionClear, &QAction::triggered, m_console, &Console::clear);
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(m_ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(m_ui->actionTerminal,&QAction::triggered,this,&MainWindow::handleTerminal);
    connect(m_ui->actionDebug,&QAction::triggered,m_debug,&debug::show);
    connect(m_ui->actionMonitor,&QAction::triggered,m_monitor,&monitor::show);
}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}

void MainWindow::showWriteError(const QString &message)
{
    QMessageBox::warning(this, tr("Warning"), message);
}

void MainWindow::fan_even_set(int val)
{
    writeData(QString("e$%1$").arg(val).toLocal8Bit());
    qDebug()<<QString("e$%1$").arg(val);
}

void MainWindow::fan_gust_set(int period, int pwm_down, int pwm_up)
{
    //validator
    if( m_ui->gust_lower_limit_slider->value() >=
         m_ui->gust_upper_limit_slider->value()){
        QMessageBox::warning(this, tr("Error"), "Gust mode WARNING : "
                                                "upper limit cannot be assigned smaller than lower limit!!! ");
        qDebug()<<QString("low:%1,high:%1").
                    arg(m_ui->gust_lower_limit_slider->value())
                        .arg(m_ui->gust_upper_limit_slider->value());
    }else{
        writeData(QString("g$%1,%2,%3$").arg(period).
                  arg(pwm_down).arg(pwm_up).toLocal8Bit());

        qDebug()<<QString("g$%1,%2,%3$").arg(period).
                   arg(pwm_down).arg(pwm_up).toLocal8Bit();

    }
}

void MainWindow::fan_sheer_set()
{
    //
    if(m_sheer_list_count != 20 or m_sheer_mode_list.size()!= 20){
        QMessageBox::warning(this, tr("Error"), "There must be 20 values!!!");
        return;
    }
    int dr;
    auto direction = m_ui->sheer_comboBox->currentText();
    if(direction == "Row")dr=0;
    if(direction == "Column")dr=1;

    for (int i = 0; i < m_sheer_mode_list.size(); ++i) {
        auto item = m_sheer_mode_list[i];
        writeData(QString("s$%1,%2,%3$").arg(dr).arg(i+1).arg(item).toLocal8Bit());
        //qDebug()<<QString("s$%1,%2,%3$").arg(dr).arg(i+1).arg(item).toLocal8Bit();
        QEventLoop loop;
        QTimer::singleShot(50, &loop, &QEventLoop::quit); // Pause formilliseconds)
        loop.exec();
    }

}




void MainWindow::on_terminalWidget_destroyed()
{
    qDebug()<<"ok";
}


void MainWindow::on_EvenmodehorizontalSlider_sliderMoved(int position)
{
    m_ui->EvenmodespinBox->setValue(m_ui->EvenmodehorizontalSlider->value());
    if(m_ui->checkBox_even_auto->isChecked()){
        fan_even_set(m_ui->EvenmodespinBox->value());
    }
}


void MainWindow::on_EvenmodespinBox_valueChanged(int arg1)
{
    m_ui->EvenmodehorizontalSlider->setValue(m_ui->EvenmodespinBox->value());
    if(m_ui->checkBox_even_auto->isChecked()){
        fan_even_set(m_ui->EvenmodespinBox->value());
    }
}


void MainWindow::on_uploadButton_clicked()
{
    auto current_page=m_ui->tabWidget->currentWidget();
    auto current_page_name = current_page->objectName();
    qDebug()<<current_page_name;
    if(current_page_name == "EvenModeTab"){
        fan_even_set(m_ui->EvenmodespinBox->value());
    }
    if(current_page_name == "GustModeTab"){
        fan_gust_set(m_ui->gust_period_slider->value(),
                     m_ui->gust_lower_limit_slider->value(),
                     m_ui->gust_upper_limit_slider->value());

    }
    if(current_page_name == "SheerModeTab"){

        fan_sheer_set();
    }

}


void MainWindow::on_actionAboutMe_triggered()
{
    aboutme m(this);
    m.exec();
}


void MainWindow::on_stopButton_clicked()
{
    writeData(QString("p$$").toLocal8Bit());
    qDebug()<<"stop";
}


void MainWindow::on_gust_upper_limit_slider_sliderMoved(int position)
{
    m_ui->gust_upper_limit_spinbox->setValue(m_ui->gust_upper_limit_slider->value());
}


void MainWindow::on_gust_lower_limit_slider_sliderMoved(int position)
{
    m_ui->gust_lower_limit_spinbox->setValue(m_ui->gust_lower_limit_slider->value());
}


void MainWindow::on_gust_upper_limit_spinbox_valueChanged(int arg1)
{
    m_ui->gust_upper_limit_slider->setValue( m_ui->gust_upper_limit_spinbox->value());
}


void MainWindow::on_gust_lower_limit_spinbox_valueChanged(int arg1)
{
    m_ui->gust_lower_limit_slider->setValue( m_ui->gust_lower_limit_spinbox->value());
}


void MainWindow::on_gust_period_slider_sliderMoved(int position)
{
    m_ui->gust_period_spinbox->setValue(m_ui->gust_period_slider->value());
}


void MainWindow::on_gust_period_spinbox_valueChanged(int arg1)
{
    m_ui->gust_period_slider->setValue(m_ui->gust_period_spinbox->value());
}


void MainWindow::on_sheer_mode_append_button_clicked()
{
    //ui change

    if(m_sheer_list_count >=20){
        QMessageBox::warning(this, tr("Error"),"List is full.");
        return;
    }
    m_sheer_list_count ++;
    m_ui->sheer_count_label->setText(QString("%1").arg(m_sheer_list_count));
    // Create a QStringListModel to store the data
    //int val = m_ui->sheer_spinBox->value();
    QString item= QString("%1").arg(m_ui->sheer_spinBox->value());
    m_dataList << item;
    m_model.setStringList(m_dataList);

    m_ui->listView->setModel(&m_model);

    //upload change
    m_sheer_mode_list.append(m_ui->sheer_spinBox->value());

}



void MainWindow::on_sheer_clear_button_clicked()
{
     //ui change
    m_dataList.clear();
    m_model.setStringList(m_dataList);

    m_ui->listView->setModel(&m_model);
    m_sheer_list_count =0;
    m_ui->sheer_count_label->setText(QString("%1").arg(m_sheer_list_count));

    //upload change
    m_sheer_mode_list.clear();

}

