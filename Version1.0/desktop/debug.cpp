#include "debug.h"
#include "ui_debug.h"
#include <QMessageBox>
debug::debug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::debug)
{
    ui->setupUi(this);



}

debug::~debug()
{
    delete ui;
}

void debug::readData(const QByteArray &data)
{
    ui->plainTextEdit->setPlainText(data);

}

void debug::writeData(const QByteArray &data)
{
    m_serial->write(data);

    auto flag_bit = data[0];
    if(flag_bit=='q'){
         QMessageBox::information(nullptr, "Information", "STM echo test is successful");
        ui->cho_labwl->setText("OK");

    }

    if(flag_bit=='t'){
        QMessageBox::information(nullptr, "Information", "STM echo test is successful");

        auto str = data.data();


        if(data[2] == 's'){
            //start
            qDebug()<<"reset";

        }
        if(data[2] == 'd'){
            //receiving data
            ui->listWidget->addItem("ok");
             qDebug()<<"append";
        }
    }

}



void debug::on_pushButton_echo_clicked()
{
    writeData(QString("q$hello,this is windows pc$").toLocal8Bit());
}


void debug::on_testButton_clicked()
{
    writeData(QString("t$$").toLocal8Bit());
}

