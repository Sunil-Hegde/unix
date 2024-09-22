#include<iostream>
#include<pthread.h>
using namespace std;

void* countTo100(void *arg){
    int id = *(int *)arg;
    for(int i = 0; i < 100; i++){
        cout<<"Thread: "<<id<<", Count: "<<i+1<<endl;
    }
    delete (int *)arg;
    return nullptr;
}

int main(){
    const int numberOfThreads = 2;
    pthread_t threads[numberOfThreads];
    for(int i = 0; i < numberOfThreads; i++){
        int* id = new int(i);
        pthread_create(&threads[i], nullptr, countTo100, id);
    }
    for(auto& thread : threads){
        pthread_join(thread, nullptr);
    }
    return 0;
}