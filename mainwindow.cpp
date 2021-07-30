#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    en.load("../lang/lang_English.qm");
    ch.load("../lang/lang_Chinese.qm");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0)
        qApp->installTranslator(&ch);
    else
        qApp->installTranslator(&en);
    ui->retranslateUi(this);
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, tr("一天"), tr("两天"));
}

void MainWindow::on_pushButton_2_clicked()
{
    SmallWin f(this);
    f.exec();
}
