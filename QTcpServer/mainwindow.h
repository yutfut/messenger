#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <QByteArray>
#include <QDebug>

#include <vector>

#include "../lib/headers/message_protocol.h"

#include "../project/include/sql.h"

#define NO_SENDER_ID -1

namespace Ui {
    class MainWindow;
}
struct userAtserver {
    int idusersoc;
    QTcpSocket *clientSocket;
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
    void sendTouser(MessageProtocol &message, int dialogID);

signals:
    void sendMessage(MessageProtocol &message, int dialogID);
private:
    Ui::MainWindow *ui;
    QTcpSocket *_sok, *clientSocket;
    QTcpServer *tcp_Server;
    int server_status;
    QList<userAtserver> SClients;
    std::vector<int> state;

    UserManagerSQL userManager;
    DialogManagerSQL dialogManager;
    MessageManagerSQL messageManager;

    int addUsertodatabase(MessageProtocol &messageProtocol);
    int addMessagetodatabase(MessageProtocol &messageProtocol, int userID, int &dialogID);
};

#endif // MAINWINDOW_H
