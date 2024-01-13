#ifndef DEBUG_H
#define DEBUG_H

#include <QDialog>
#include "mainwindow.h"
#include <QMessageBox>
namespace Ui {
class debug;
}

class debug : public QDialog
{
    Q_OBJECT

public:
    explicit debug(QWidget *parent = nullptr);
    ~debug();
    void setSerial(QSerialPort * serial){m_serial=(serial);};

private:
    Ui::debug *ui;
    QSerialPort *m_serial = nullptr;

public slots:
    void readData(const QByteArray &data);
    void writeData(const QByteArray &data);
private slots:
    void on_pushButton_echo_clicked();
    void on_testButton_clicked();
};

#endif // DEBUG_H
