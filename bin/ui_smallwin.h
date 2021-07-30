/********************************************************************************
** Form generated from reading UI file 'smallwin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLWIN_H
#define UI_SMALLWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SmallWin
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *SmallWin)
    {
        if (SmallWin->objectName().isEmpty())
            SmallWin->setObjectName(QString::fromUtf8("SmallWin"));
        SmallWin->resize(396, 122);
        pushButton_2 = new QPushButton(SmallWin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 50, 75, 23));
        pushButton = new QPushButton(SmallWin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 50, 75, 23));

        retranslateUi(SmallWin);

        QMetaObject::connectSlotsByName(SmallWin);
    } // setupUi

    void retranslateUi(QDialog *SmallWin)
    {
        SmallWin->setWindowTitle(QApplication::translate("SmallWin", "\345\255\220\347\252\227\345\217\243", nullptr));
        pushButton_2->setText(QApplication::translate("SmallWin", "\344\272\224\346\243\265\346\240\221", nullptr));
        pushButton->setText(QApplication::translate("SmallWin", "\344\270\200\346\243\265\346\240\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmallWin: public Ui_SmallWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWIN_H
