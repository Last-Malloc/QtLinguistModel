#include "smallwin.h"
#include "ui_smallwin.h"

SmallWin::SmallWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SmallWin)
{
    ui->setupUi(this);
}

SmallWin::~SmallWin()
{
    delete ui;
}

void SmallWin::on_pushButton_clicked()
{
    QMessageBox::information(this, tr("一棵树"), tr("我有一棵树"));
}

void SmallWin::on_pushButton_2_clicked()
{
    QMessageBox::information(this, tr("五棵树"), tr("我有五棵树"));
}
