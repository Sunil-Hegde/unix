#include<iostream>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
using namespace std;

struct Message{
    long mtype;
    char mtext[100];
};

int main(){
    key_t key = ftok("/tmp", 1);
    int msgID = msgget(key, 0666 | IPC_CREAT);

    Message message = {1, "Hello from sender."};
    msgsnd(msgID, &message, sizeof(message.mtext), 0);
    cout<<"Message sent"<<endl;
    return 0;
}