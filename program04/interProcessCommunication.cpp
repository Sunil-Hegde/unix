#include<iostream>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<wait.h>
#include<cstring>
using namespace std;

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main(){
    int sharedMemoryID = shmget(ftok(".", SHM_KEY), SHM_SIZE, IPC_CREAT | 0666);
    char* sharedMemoryPointer = (char *)shmat(sharedMemoryID, NULL, 0);
    strcpy(sharedMemoryPointer, "Hello from shared memory!");
    if(fork()==0){
        cout<<"Child: "<<sharedMemoryPointer<<endl;
        shmdt(sharedMemoryPointer);
    } else {
        wait(NULL);
        shmdt(sharedMemoryPointer);
        shmctl(sharedMemoryID, IPC_RMID, NULL);
    }
    return 0;
}