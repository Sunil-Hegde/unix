#include<iostream>
#include<unistd.h>
using namespace std;

int main(int argc, char* argv[]){
    if(argc!=3){
        cout<<argv[0]<<" sourceFile destinationFile"<<endl;
        return 1;
    }
    const char* sourceFile = argv[1];
    const char* destinationFile = argv[2];

    if(link(sourceFile, destinationFile) == 0){
        cout<<"Hardlink created: "<<destinationFile<<" -> "<<sourceFile<<endl;
        return 0;
    } else {
        perror("Error creating hard link!");
        return 2;
    }
}