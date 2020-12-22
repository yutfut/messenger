#include "dialogs.h"
#include "ui_dialogs.h"
#include <QPixmap>
#include <QStackedWidget>
#include <QTime>
#include <QFileDialog>
#include <QDesktopServices>
//#include "../lib/headers/message_protocol.h"
//#include "../include/dialog.h"

Dialog::Dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::delete_input_zone() {
    ui->input->clear();
}

/*void Dialog::on_file_clicked()
{
    return;
}*/

void Dialog::on_send_button_clicked()
{
    QString text = ui->input->toPlainText();
    QTime timer;
    timer = QTime::currentTime();
    auto time = timer.toString();
    if (text != "") {
        QTime timer;
        timer = QTime::currentTime();
        auto time = timer.toString();
        QString msg = QString(time + " " + text);
        ui->textBrowser->append(msg);
        delete_input_zone();
    }
}

void Dialog::on_file_button_clicked()
{
    auto path = QFileDialog::getOpenFileName();
    //QDesktopServices::openUrl(QUrl::fromLocalFile(path));
    QString text = "File:" + path;
    ui->textBrowser->append(text);
    delete_input_zone();
    //dlg_client.addFile(proptocol,path);
}

void Dialog::on_add_group_dlg_clicked()
{
    vbox->add_dialog();
}
