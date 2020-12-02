#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class Server {
public:
    unsigned short port = 1234;
    Server();

    ~Server();

    void startServer();
};

#endif //SERVER_SERVER_H
