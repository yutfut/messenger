#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>

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

void Dialog::chat() {
    QString msg = ui->input->toPlainText();
    //ui->input->append(msg);
            /*oid Dialog::addToLog(QString text, QString time, QColor color) {
                QString message = QString(time + " " + text);

                ui->lwLog->setTextColor(color);
                ui->lwLog->append(message);
            }    */

}

void Dialog::on_file_clicked()
{
    return;
}

void Dialog::on_send_button_clicked()
{

}
