// server.cpp
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address = {AF_INET, htons(8080), INADDR_ANY};
    bind(server_fd, (sockaddr*)&address, sizeof(address));
    listen(server_fd, 1);
    std::cout << "Server listening on port 8080...\n";

    int client_socket = accept(server_fd, nullptr, nullptr);
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    std::cout << "Message from client: " << buffer << std::endl;

    const char *response = "Hello from Server!";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
    close(server_fd);
    return 0;
}
