#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main(){
    const char* inputFile = "source.txt";
    const char* outputFile = "destination.txt";

    int sourceFileDirective = open(inputFile, O_RDONLY);
    if(sourceFileDirective == -1){
        perror("Error opening source file!");
        return 1;
    }

    int destinationFileDirective = open(outputFile, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if(destinationFileDirective == -1){
        perror("Error opening/creating desination file!");
        return 1;
    }

    char buffer[4096];
    ssize_t bytesRead, bytesWritten;

    while((bytesRead = read(sourceFileDirective, buffer, sizeof(buffer)))>0){
        bytesWritten = write(destinationFileDirective, buffer, bytesRead);
        if(bytesWritten != bytesRead){
            perror("Error writing to destination file!");
            close(sourceFileDirective);
            close(destinationFileDirective);
            return 1;
        }
    }
    close(sourceFileDirective);
    close(destinationFileDirective);
    cout<<"File copied Successfully!"<<endl;
    return 0;
}
