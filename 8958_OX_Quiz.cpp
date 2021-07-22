#include <iostream>
#include <string>

int main() {
    int t;
    std::string line;

    std::cin >> t;

    for (int i=0; i<t; i++) {
        std::cin >> line;

        int ans = 0;
        int succO = 0;

        for (char const &c: line) {
            if (c == 'O') {
                succO++;
                ans += succO;
            } else {
                succO = 0;
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}