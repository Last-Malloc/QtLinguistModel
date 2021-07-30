#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator ch;
    QTranslator en;
    en.load("../lang/lang_English.qm");
    ch.load("../lang/lang_Chinese.qm");
    // 获取系统语言环境
    QLocale locale;
    if (locale.language() == QLocale::Chinese)
    {
        a.installTranslator(&ch);
    }
    else
    {
        a.installTranslator(&en);
    }
    MainWindow w;
    w.show();

    return a.exec();
}
