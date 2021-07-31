#include <iostream>
#include <set>
#include <cstring>

int main() {
    int n, ans = 0;
    char word [101];

    std::cin >> n;

    for (int i=0; i<n; i++) {
        std::cin >> word;
        std::set<char> charCheck;
        bool isGroupWord = true;

        int j=0;

        while (j < strlen(word)) {
            if (charCheck.find(word[j]) != charCheck.end()){
                isGroupWord = false;
                break;
            }

            charCheck.insert(word[j]);
            while (word[j] == word[j+1]) j++;

            j++;
        }

        if (isGroupWord) ans++;
    }

    std::cout << ans;

    return 0;
}