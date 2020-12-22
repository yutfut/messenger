#ifndef DIALOGS_H
#define DIALOGS_H

#include <QMainWindow>
#include <vector>
#include <QTextBrowser>
//#include "../lib/headers/message_protocol.h"
//#include "../include/dialog.h"
#include "verticalbox.h"

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
    //void on_letter_clicked();

    //void on_file_clicked();

    void on_send_button_clicked();

    void on_file_button_clicked();

    void on_add_group_dlg_clicked();

private:
    void delete_input_zone();
    Ui::Dialog *ui;
    QTextBrowser *br;
    /*MessageProtocol protocol;
    Dialogues dlg_client;*/
    std::vector<int> ert;
    VerticalBox * vbox;
};

#endif // DIALOGS_H
