#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    pid_t childThread = fork();
    if(childThread == -1){
        perror("Error creating child fork!");
        return 1;
    }
    for(int i = 0;i < 5; i++){
        if(childThread == 0){
            cout<<"Child process: "<<i+1<<endl;
        } else {
            cout<<"Parent process: "<<i+1<<endl;
        }
        sleep(1);
    }
    return 0;
}