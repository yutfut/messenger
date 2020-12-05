#ifndef DIALOG_H
#define DIALOG_H

#include "../lib/headers/message_protocol.h"

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTcpServer>
#include <QMessageBox>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    void newMessage(QString);

private slots:
    void onSokConnected();
    void onSokDisconnected();
    void onSokReadyRead();
    void onSokDisplayError(QAbstractSocket::SocketError socketError);

    void on_pbConnect_clicked();
    void on_pbDisconnect_clicked();
    void on_pbt_Send_clicked();
    void on_message_Edit_textEdited(const QString &arg1);

private:
    Ui::Dialog *ui;
    QTcpSocket *socket;
    bool isButtonClicked;

    void addToLog(QString text, QColor color = Qt::black);
    void displayError(const QString &error);
    void disableButtons(const bool state_1, const bool state_2 = true);

};

#endif // DIALOG_H
