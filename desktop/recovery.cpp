#include "recovery.h"
#include "ui_recovery.h"
#include <QMessageBox>

Recovery::Recovery(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Recovery)
{
    ui->setupUi(this);
}

Recovery::~Recovery()
{
    delete ui;
}


void Recovery::on_pushButton_clicked()
{
    QString login = ui->login->text();
    if (login == "") {
        ui->statusbar->showMessage("enter login");
    } else {
        ui->statusbar->showMessage("Success.Sending check code...");
    }
}

void Recovery::on_pushButton_2_clicked()
{
    QString check_code = ui->check_code->text();
    if (check_code == "far123") {
        QMessageBox::information(this,"snjv", "Success, check code is equal.Connection...");
        hide();
        add_pass_window = new Newpass(this);
        add_pass_window->show();
    } else {
        ui->statusbar->showMessage("check code was entered is incorrect");
    }
}
