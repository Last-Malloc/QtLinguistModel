#ifndef SMALLWIN_H
#define SMALLWIN_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class SmallWin;
}

class SmallWin : public QDialog
{
    Q_OBJECT

public:
    explicit SmallWin(QWidget *parent = nullptr);
    ~SmallWin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SmallWin *ui;
};

#endif // SMALLWIN_H
