#include "../include/server.h"

Server::Server() {

}

Server::~Server() {

}

void closeServer(int &server_sock) {
    close(server_sock);
    std::cout << "\tSERVER STOP\n";
}

void handle(int &server_sock) {
    while (true) {
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len;
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_len);

        char buffer[256];
        int r = read(client_sock, buffer, sizeof(buffer));
        buffer[r] = '\0';

        std::cout << "receive " << buffer << std::endl;

        close(client_sock);
        if (buffer[0] == '#') {
            break;
        }
    }

    closeServer(server_sock);
}

void Server::startServer() {

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind:\n");
        return;
    } else {
        std::cout << "\tSERVER START\n";
    }

    listen(server_sock, 10);

    handle(server_sock);
}
