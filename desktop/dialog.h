#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>

namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_letter_clicked();

    void on_file_clicked();

    void on_send_button_clicked();

private:
    void chat();
    Ui::Dialog *ui;
};

#endif // DIALOG_H
