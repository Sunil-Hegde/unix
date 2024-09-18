#include<iostream>
#include<pthread.h>
using namespace std;

void* countTo100(void *arg){
    int id = *(int *)arg;
    for(int i = 0; i<100;i++){
        cout<<"Thread: "<<id<<", Count: "<<i+1<<endl;
    }
    delete (int *)arg;
    return nullptr;
} 

int main(){
    const int numOfThreads = 2;
    pthread_t threads[numOfThreads];

    for(int i = 0; i< numOfThreads; i++){
        int *id = new int(i);
        if(pthread_create(&threads[i], nullptr, countTo100, id)){
            perror("Error creating thread");
            return -1;
        }
    }

    for(auto& thread : threads){
        pthread_join(thread, nullptr);
    }
    return 0;
}
