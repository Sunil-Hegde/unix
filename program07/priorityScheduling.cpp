#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Process{
    int processID;
    int priority;
    int burstTime;
    int turnAroundTime;
    int waitTime;
}Process;

bool hasMorePriority(Process a, Process b){
    return a.priority<b.priority;
}

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<Process> processes(n);
    cout<<"Enter process details: "<<endl;
    for(int i = 0; i < n; i++){
        cout<<"\tProcess "<<i+1<<":\n";
        processes[i].processID = i+1;
        cout<<"\t\tPriority: ";
        cin>>processes[i].priority;
        cout<<"\t\tBurst Time: ";
        cin>>processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), hasMorePriority);

    processes[0].waitTime = 0;
    processes[0].turnAroundTime = processes[0].burstTime + processes[0].waitTime;
    for(int i = 1; i < n; i++){
        processes[i].waitTime = processes[i-1].turnAroundTime;
        processes[i].turnAroundTime = processes[i].waitTime + processes[i].burstTime;
    }

    int totalWaitTime = 0, totalTurnAroundTime = 0;
    for(int i = 0; i < n; i++){
        totalWaitTime+=processes[i].waitTime;
        totalTurnAroundTime+=processes[i].turnAroundTime;
    }

    cout<<"Average Wait time: "<<(float)totalWaitTime/n<<endl;
    cout<<"Average Turn Around Time: "<<(float)totalTurnAroundTime/n<<endl;
    return 0;
}