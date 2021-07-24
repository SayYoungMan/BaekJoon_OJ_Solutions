#include <iostream>
#include <string>

#define MAX_LEN 1000000

int main() {
    char line [MAX_LEN];
    int c;

    std::cin.getline(line, MAX_LEN);

    char *token = strtok(line, " ");
    
    while (token != NULL) {
        c += 1;
        token = strtok(NULL, " ");
    }
    
    std::cout << c << std::endl;

    return 0;
}