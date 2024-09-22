// client.cpp
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_address = {AF_INET, htons(8080)};
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr); // IP address of the server (local)

    connect(client_fd, (sockaddr*)&server_address, sizeof(server_address));
    
    const char *message = "Hello from Client!";
    send(client_fd, message, strlen(message), 0);
    
    char buffer[1024] = {0};
    read(client_fd, buffer, 1024);
    std::cout << "Message from server: " << buffer << std::endl;

    close(client_fd);
    return 0;
}
