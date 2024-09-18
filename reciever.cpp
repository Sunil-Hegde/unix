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
    int messageID = msgget(key, 0666 | IPC_CREAT);

    Message message;
    msgrcv(messageID, &message, sizeof(message.mtext), 1, 0);
    cout<<"Message recieved: "<<message.mtext<<endl;
    return 0;
}