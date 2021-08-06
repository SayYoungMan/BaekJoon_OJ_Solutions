#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    while (true) {
        std::cin >> a >> b;

        if (a == 0 && b == 0) break;

        if (a % b == 0) std::cout << "multiple\n";
        else if (b % a == 0) std::cout << "factor\n";
        else std::cout << "neither\n";
    }

    return 0;
}