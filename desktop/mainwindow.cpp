#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/chat/img/main.webp");
    int w = ui->main_picture->width();
    int h = ui->main_picture->width();
    ui->main_picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();
    if (login == "log" && password == "pas") {
        ui->statusbar->showMessage("Авторизация успешна.Подключение к серверу...");
        QMessageBox::information(this,"snjv", "success!");
        hide();
        dlg_window = new Dialog(this);
        dlg_window->show();
    } else {
        ui->statusbar->showMessage("Ошибка доступа.Попробуйте еще раз");
        QMessageBox::critical(this,"snjv", "not success!");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    reg_window = new Registration(this);
    reg_window->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    hide();
    rec_window_1 = new Recovery(this);
    rec_window_1->show();
}
























