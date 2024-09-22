#include<iostream>
using namespace std;

int main(){
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    
    int burstTime[n], remainingTime[n], turnAroundTime[n];
    int waitTime[n] = {0}, completionTime[n] = {0};
    
    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    cout << "Enter burst times for the processes: " << endl;
    for(int i = 0; i < n; i++){
        cout << "\tBurst time for Process " << i + 1 << " : ";
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i];
    }

    int totalTime = 0;
    bool unfinished = true;

    // Round Robin Logic
    while (unfinished) {
        unfinished = false;  // Assume all processes are finished
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {  // Process still needs execution
                unfinished = true;

                if (remainingTime[i] > timeQuantum) {
                    remainingTime[i] -= timeQuantum;
                    totalTime += timeQuantum;
                } else {
                    totalTime += remainingTime[i];
                    waitTime[i] = totalTime - burstTime[i];  // Calculate wait time
                    completionTime[i] = totalTime;
                    remainingTime[i] = 0;  // Process finished
                }
            }
        }
    }

    // Calculate Turnaround time and total wait/turnaround times
    int totalWaitTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitTime[i];  // Turnaround time = Burst + Wait
        totalWaitTime += waitTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    // Output Average times
    cout << "Average Wait Time: " << (float)totalWaitTime / n << endl;
    cout << "Average Turn Around Time: " << (float)totalTurnAroundTime / n << endl;
    
    return 0;
}
