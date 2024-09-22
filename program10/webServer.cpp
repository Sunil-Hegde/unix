#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address = {AF_INET, htons(8080), INADDR_ANY};
    bind(server_fd, (sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);
    std::cout << "Server running at http://localhost:8080\n";

    const char *htmlResponse = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 46\n\n<html><body><h1>Hello from C++!</h1></body></html>";
    while (true) {
        int new_socket = accept(server_fd, nullptr, nullptr);
        char buffer[30000] = {0};
        read(new_socket, buffer, 30000);
        send(new_socket, htmlResponse, strlen(htmlResponse), 0);
        close(new_socket);
    }

    return 0;
}
