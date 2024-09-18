#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    int pipe_fd[2];
    pipe(pipe_fd);
    pid_t childProcessID = fork();

    if(childProcessID > 0){
        close(pipe_fd[0]);
        string msg = "Hello from parent.";
        write(pipe_fd[1], msg.c_str(), msg.length());
        close(pipe_fd[1]);
    } else {
        close(pipe_fd[1]);
        char buffer[50];
        ssize_t bytes = read(pipe_fd[0], buffer, sizeof(buffer));
        buffer[bytes] = '\0';
        cout<<"Message recieved: "<<buffer<<endl;
        close(pipe_fd[0]);
    }
    return 0;
}