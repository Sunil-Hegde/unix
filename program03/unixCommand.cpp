#include<iostream>
#include<unistd.h>
using namespace std;

int main(int argc, char* argv[]){
    if(argc!=3){
        cout<<"Input format: "<<argv[0]<<" sourceFile.txt destinationFile.txt"<<endl;
        return 1;
    }
    const char* sourceFile = argv[1];
    const char* destinationFile = argv[2];
    if(link(sourceFile, destinationFile) == 0){
        cout<<"Hard link created: "<<destinationFile<<" -> "<<sourceFile<<endl;
        return 0;
    } else {
        perror("Error creating Hard link!");
        return 1;
    }
}