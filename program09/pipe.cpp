#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    int pipeFileDescriptor[2];
    pipe(pipeFileDescriptor);
    pid_t childProcessID = fork();

    if(childProcessID > 0){
        close(pipeFileDescriptor[0]);
        string msg = "Hello from Parent!";
        write(pipeFileDescriptor[1], msg.c_str(), msg.length());
        close(pipeFileDescriptor[1]);
    } else {
        close(pipeFileDescriptor[1]);
        char buffer[50];
        ssize_t bytes = read(pipeFileDescriptor[0], buffer, sizeof(buffer));
        buffer[bytes] = '\0';
        cout<<"Message recieved by Child: "<<buffer<<endl;
        close(pipeFileDescriptor[0]);
    }
    return 0;
}