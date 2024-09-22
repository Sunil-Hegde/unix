#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    cout<<"Number of Clock ticks: "<<sysconf(_SC_CLK_TCK)<<endl;
    cout<<"Maximum number of Child processes: "<<sysconf(_SC_CHILD_MAX)<<endl;
    cout<<"Maximum number of Characters in Path: "<<pathconf("/",_PC_PATH_MAX)<<endl;
    cout<<"Maximum number of Characters in File name: "<<pathconf("/",_PC_NAME_MAX)<<endl;
    cout<<"Maximum number of Processes: "<<sysconf(_SC_OPEN_MAX);
    return 0;
}