#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <vector>
#include <unistd.h>
using namespace std;

#define BUF_SIZE 5
vector<int> buffer;
sem_t mutex, slotsAvailable, itemsAvailable;

void* producer(void*) {
    while (true) {
        sleep(1); 
        int item = rand() % 100;
        sem_wait(&slotsAvailable); // Wait for an empty slot
        sem_wait(&mutex);          // Enter critical section
        buffer.push_back(item);
        cout << "Produced: " << item << endl;
        sem_post(&mutex);          // Exit critical section
        sem_post(&itemsAvailable); // Signal item available
    }
}

void* consumer(void*) {
    while (true) {
        sleep(2);
        sem_wait(&itemsAvailable); // Wait for an item
        sem_wait(&mutex);          // Enter critical section
        int item = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << item << endl;
        sem_post(&mutex);          // Exit critical section
        sem_post(&slotsAvailable); // Signal slot available
    }
}

int main() {
    pthread_t prod, cons;
    sem_init(&mutex, 0, 1);
    sem_init(&slotsAvailable, 0, BUF_SIZE); // For empty slots
    sem_init(&itemsAvailable, 0, 0);        // For available items
    
    pthread_create(&prod, nullptr, producer, nullptr);
    pthread_create(&cons, nullptr, consumer, nullptr);
    
    pthread_join(prod, nullptr);
    pthread_join(cons, nullptr);
    
    sem_destroy(&mutex);
    sem_destroy(&slotsAvailable);
    sem_destroy(&itemsAvailable);
    
    return 0;
}
