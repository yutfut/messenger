#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "dialogs.h"

#include <QMainWindow>

namespace Ui {
class Registration;
}

class Registration : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_send_code_clicked();

    void on_end_reg_clicked();

private:
    Ui::Registration *ui;
    Dialog *dlg_window;
};

#endif // REGISTRATION_H
