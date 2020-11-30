#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

class MyClient;

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

    void display_message(const QString &str);
    void Display_error(const QString &error);
    void Disable_buttons(const bool state_1, const bool state_2 = true);

    void on_pbt_Send_clicked();

    void on_message_Edit_textEdited(const QString &arg1);

private:
    Ui::Dialog *ui;
    QTcpSocket *_sok;
    quint16 _blockSize;
    QString _name;
    void AddToLog(QString text, QColor color = Qt::black);

};

#endif // DIALOG_H
