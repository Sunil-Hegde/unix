#include <iostream>

extern char** environ;  // Declaration of the environment variables array

int main() {
    char** env = environ;  // Pointer to the environment variables array
    // Loop through each environment variable and print it
    while (*env != nullptr) {
        std::cout << *env << std::endl;
        env++;
    }
    return 0;
}
