#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    pid_t childProcess = fork();
    if(childProcess==-1){
        perror("Error creating a Child process!");
        return 1;
    }
    for(int i = 1; i <= 5; i++){
        if(childProcess==0){
            cout<<"Child process: "<<i<<endl;
        } else {
            cout<<"Parent process: "<<i<<endl;
        }
        sleep(1);
    }
    return 0;
}