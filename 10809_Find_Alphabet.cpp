#include <iostream>
#include <string>

int main() {
    int alpha [26];
    std::string word;
    char c;

    for (int i=0; i<26; i++) {
        alpha[i] = -1;
    }

    std::cin >> word;

    for (int i=0; i < word.size(); i++) {
        c = word[i];
        if (alpha[(int)c - 97] == -1) {
            alpha[(int)c - 97] = i;
        }
    }

    for (int i=0; i<26; i++) {
        std::cout << alpha[i] << " ";
    }

    return 0;
}