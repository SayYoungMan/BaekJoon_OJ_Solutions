#include <iostream>
#include <string>

int main() {
    int occ [26] = { 0 };
    int most = 0;
    char ans;
    bool dup = true;
    std::string word;

    std::cin >> word;

    for (const char &c: word) {
        char lc = tolower(c);
        occ[(int)lc - 'a'] += 1;

        if (occ[(int)lc - 'a'] > most) {
            most = occ[(int)lc - 'a'];
            dup = false;
        } else if (occ[(int)lc - 'a'] == most) {
            dup = true;
        }
    }

    if (dup == true) {
        std::cout << "?";
    } else {
        for (int i=0; i<26; i++) {
            if (occ[i] == most) {
                ans = (char)(i + 65);
                std::cout << ans;
            }
        }
    }

    return 0;
}