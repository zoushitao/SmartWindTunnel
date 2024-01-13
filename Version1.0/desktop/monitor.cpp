#include "monitor.h"
#include "ui_monitor.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QColor>
monitor::monitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::monitor)
{


    ui->setupUi(this);

    for(int i=0;i <40;i++){
        for(int j=0;j<40;j++){
            m_val_mat[i][j]=0;
        }
    }

    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(columnCount);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);;
    //
    const int row_height=5;
    const int col_width=5;
    for (int row = 0; row < rowCount; ++row) {
        ui->tableWidget->setRowHeight(row, row_height);
    }
    for (int col = 0; col < columnCount; ++col) {
        ui->tableWidget->setColumnWidth(col, col_width);
    }

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem();
            auto color = QColor(123,123,123);
            //color.setBlue(180);
            item->setBackground(color);

            ui->tableWidget->setItem(row, col, item);
        }
    }

}

monitor::~monitor()
{
    delete ui;
}

/*
const QColor monitor::mapColor(int val)
{
    QVector<QColor> colors = { QColor(255,255,255),QColor(212,216,255),QColor(183,191,255)
                              ,QColor(152,163,255),QColor(122,136,255),QColor(95,111,255),
                              QColor(80,97,255),QColor(63,82,255),QColor(50,70,255),
        QColor(28,42,255),QColor(0,25,255),QColor(0,0,255)};

    return colors[int(double(val)/4000.0*12.0)];


}

*/


