// Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
// Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>

#include <QVector>
#include <QListView>
#include <QStringListModel>
#include "monitor.h"
QT_BEGIN_NAMESPACE

class QLabel;
class QTimer;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class Console;
class SettingsDialog;
class debug;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);
    void handleBytesWritten(qint64 bytes);
    void handleWriteTimeout();

    void handleTerminal();

    void on_terminalWidget_destroyed();

    void on_EvenmodehorizontalSlider_sliderMoved(int position);

    void on_EvenmodespinBox_valueChanged(int arg1);

    void on_uploadButton_clicked();

    void on_actionAboutMe_triggered();

    void on_stopButton_clicked();

    void on_gust_upper_limit_slider_sliderMoved(int position);

    void on_gust_lower_limit_slider_sliderMoved(int position);

    void on_gust_upper_limit_spinbox_valueChanged(int arg1);

    void on_gust_lower_limit_spinbox_valueChanged(int arg1);

    void on_gust_period_slider_sliderMoved(int position);

    void on_gust_period_spinbox_valueChanged(int arg1);

    void on_sheer_mode_append_button_clicked();



    void on_sheer_clear_button_clicked();

private:
    void initActionsConnections();

private:
    void showStatusMessage(const QString &message);
    void showWriteError(const QString &message);

    Ui::MainWindow *m_ui = nullptr;
    QLabel *m_status = nullptr;
    Console *m_console = nullptr;
    SettingsDialog *m_settings = nullptr;
    qint64 m_bytesToWrite = 0;
    QTimer *m_timer = nullptr;
    QTimer *m_clear_timer = nullptr;
    QSerialPort *m_serial = nullptr;
    debug *m_debug=nullptr;
    monitor *m_monitor=nullptr;
    QVector<unsigned int> m_sheer_mode_list;
    //model for sheer mode
    QStringListModel m_model;
    QStringList m_dataList;
    int m_sheer_list_count =0;

    /*User Codes*/
private :
    bool terminal_on = false;

    /*End user codes*/

    /*******Fan logfic******/
    void fan_even_set(int);
    void fan_gust_set(int,int,int);
    void fan_sheer_set(void);
};

#endif // MAINWINDOW_H
