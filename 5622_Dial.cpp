#include <iostream>
#include <string>

int main() {
    int ans = 0;
    std::string line;

    std::cin >> line;

    for (char& c : line) {
        if (c == 'A' || c == 'B' || c == 'C') {
            ans += 3;
        }
    }

    std::cout << ans;

    return 0;
}