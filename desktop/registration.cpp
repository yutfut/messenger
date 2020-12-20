#include "registration.h"
#include "ui_registration.h"
#include <QCheckBox>
#include <QMessageBox>
//#include <QStandardItem>
#include <QAbstractButton>

Registration::Registration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_checkBox_stateChanged(int arg1)
{
    ui->statusbar->showMessage("One of fields is not filled in");
    QString name = ui->user_name->text();
    QString login = ui->login->text();
    QString pass = ui->pass->text();
    QString pass_control = ui->pass_control->text();
    if ((name == "" || login == "" || pass == "" || pass_control == "" )) {
        ui->checkBox->setChecked(false);
        return;
    } else if ((name != "" || login != "" || pass != "" || pass_control != "")&& pass != pass_control) {
        ui->statusbar->showMessage("passwords are not equal");
        ui->checkBox->setChecked(false);
    } else {
        ui->statusbar->showMessage("Success.Sending check code...");
    }
}

void Registration::on_pushButton_clicked()
{
    QString check_code = ui->code_from_letter->text();
    if (check_code == "far123") {
        hide();
        dlg_window = new Dialog(this);
        dlg_window->show();
        ui->statusbar->showMessage("Success, check code is equal.Connection...");
    } else {
        ui->statusbar->showMessage("wrong check code.try again");
    }
}














