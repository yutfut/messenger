#include "newpass.h"
#include "ui_newpass.h"
#include <QMessageBox>

Newpass::Newpass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Newpass)
{
    ui->setupUi(this);
}

Newpass::~Newpass()
{
    delete ui;
}

void Newpass::on_pushButton_clicked()
{
    QString pass = ui->pass->text();
    QString control_pass = ui->control_pass->text();
    if (pass == control_pass) {
        QMessageBox::information(this,"dfgn", "Success!");
        hide();
        dlg_window = new Dialog(this);
        dlg_window->show();
    }
}
