#include<iostream>
#include<pthread.h>
using namespace std;

void* printHelloWorld(void *threadNumber){
    cout<<"Hello from Thread "<<*(int *)threadNumber<<endl;
    pthread_exit(NULL);
}

int main(){
    const int numberOfThreads = 5;
    pthread_t threads[numberOfThreads];
    for(int i = 0; i < numberOfThreads; i++){
        pthread_create(&threads[i], NULL, printHelloWorld, (void *)&i);
    }
    for(int i = 0; i < numberOfThreads; i++){
        pthread_join(threads[i], NULL);
    }
    return 0;
}