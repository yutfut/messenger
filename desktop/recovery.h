#ifndef RECOVERY_H
#define RECOVERY_H

#include <QMainWindow>
#include "newpass.h"

namespace Ui {
class Recovery;
}

class Recovery : public QMainWindow
{
    Q_OBJECT

public:
    explicit Recovery(QWidget *parent = nullptr);
    ~Recovery();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Recovery *ui;
    Newpass *add_pass_window;
};

#endif // RECOVERY_H
