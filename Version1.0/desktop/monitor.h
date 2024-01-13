#ifndef MONITOR_H
#define MONITOR_H

#include <QDialog>

//***C Defintion**//


namespace Ui {
class monitor;
}

class monitor : public QDialog
{
    Q_OBJECT

public:
    explicit monitor(QWidget *parent = nullptr);
    ~monitor();


private:
    Ui::monitor *ui;

    const int rowCount=40;
    const int columnCount=40;
    unsigned int m_val_mat[40][40];
    //const QColor mapColor(int val);
    //handle Cstyle
    //gust_handle gust_handle;




};




#endif // MONITOR_H
