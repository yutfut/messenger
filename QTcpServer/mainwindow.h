#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <QByteArray>
#include <QDebug>

namespace Ui {
    class MainWindow;
}
struct userAtserver {
    int id;
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

private:
    Ui::MainWindow *ui;
    QTcpSocket *_sok, *clientSocket;
    QTcpServer *tcp_Server;
    int server_status;
    QList<userAtserver> SClients;

    int getIdbyreceiver(int receiverId);
};

#endif // MAINWINDOW_H
