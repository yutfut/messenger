#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <QByteArray>
#include <QDebug>

#include "../lib/headers/message_protocol.h"

namespace Ui {
    class MainWindow;
}
struct userAtserver {
    int idusersoc;
    QTcpSocket *clientSocket;
    int countSendmessages;
};

class QTcpServer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_starting_clicked();
    void on_stoping_clicked();
    void newuser();
    void slotReadClient();
    void sendTouser(MessageProtocol &message, QString &messageFromclient);

signals:
    void sendMessage(MessageProtocol &message, QString &messageFromclient);
private:
    Ui::MainWindow *ui;
    QTcpSocket *_sok, *clientSocket;
    QTcpServer *tcp_Server;
    int server_status;
    QList<userAtserver> SClients;
};

#endif // MAINWINDOW_H
