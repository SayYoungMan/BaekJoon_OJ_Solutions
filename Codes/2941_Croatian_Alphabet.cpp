#include <iostream>

int main() {
    char word [102];

    std::cin >> word;
    int i = 0, count = 0;
    while (word[i] != 0) {
        if (word[i] == 'c') {
            if (word[i+1] == '=') i++;
            else if (word[i+1] == '-') i++;
        }

        else if (word[i] == 'd') {
            if (word[i+1] == 'z' && word[i+2] == '=') i += 2;
            else if (word[i+1] == '-') i++;
        }

        else if (word[i] == 'l') {
            if (word[i+1] == 'j') i++;
        }

        else if (word[i] == 'n') {
            if (word[i+1] == 'j') i++;
        }

        else if (word[i] == 's') {
            if (word[i+1] == '=') i++;
        }

        else if (word[i] == 'z') {
            if (word[i+1] == '=') i++;
        }

        i++;
        count++;
    }
    
    std::cout << count;

    return 0;
}