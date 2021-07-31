#include <iostream>

int main() {
    int n;

    std::cin >> n;

    for (int i=1; i <= n; i++) {
        for (int star=1; star <= i; star++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}