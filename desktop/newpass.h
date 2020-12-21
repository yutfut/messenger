#ifndef NEWPASS_H
#define NEWPASS_H

#include <QMainWindow>
#include "dialog.h"

namespace Ui {
class Newpass;
}

class Newpass : public QMainWindow
{
    Q_OBJECT

public:
    explicit Newpass(QWidget *parent = nullptr);
    ~Newpass();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Newpass *ui;
    Dialog *dlg_window;
};

#endif // NEWPASS_H
