#ifndef DIALOG_H
#define DIALOG_H

#include "../lib/headers/message_protocol.h"

#include <QDialog>
#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTcpServer>
#include <QMessageBox>
#include <QVariantList>
#include <QFileDialog>

namespace Ui {
    class Dialog;
}

class Dialog: public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QTcpSocket *getSocket();
    void sendServiceMessage(QString &textMessage);

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

    void on_attachmentBtn_clicked();

private:
    Ui::Dialog *ui;
    QTcpSocket *socket;
    bool isButtonClicked;
    QString filePath;
    int userId;
    int dialogId;

    void addToLog(QString text, QColor color = Qt::black);
    void displayError(const QString &error);
    void disableButtons(const bool state_1, const bool state_2 = true);
    void addFile(MessageProtocol &protocol, QString &filePath);
    void saveFiles(MessageProtocol &protocol, QString &filePath);

};

#endif // DIALOG_H
