#include "aboutme.h"
#include "ui_aboutme.h"

aboutme::aboutme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutme)
{
    ui->setupUi(this);
    QString info = "Basic instruction format:"
                   "[instruction]$[arg1],[arg2],..$ \n"
                   "### Even Mode ### \n"
                   "e$[pwm_up]$ \n";
    ui->textEdit->setText(info);
}

aboutme::~aboutme()
{
    delete ui;
}

void aboutme::on_pushButton_clicked()
{
    this->close();
}

