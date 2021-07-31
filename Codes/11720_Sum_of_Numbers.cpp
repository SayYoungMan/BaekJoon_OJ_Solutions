#include <iostream>

int main() {
    int n, sum = 0;
    char c;

    std::cin >> n;
    for (int i=0; i<n; i++) {
        std::cin >> c;

        sum += (c - '0');
    }

    std::cout << sum;

    return 0;
}