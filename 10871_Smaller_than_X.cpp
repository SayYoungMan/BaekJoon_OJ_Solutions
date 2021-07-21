#include <iostream>

int main() {
    int n, x, num;

    std::cin >> n >> x;

    for (int i=0; i<n; i++) {
        std::cin >> num;

        if (num < x) {
            std::cout << num << " ";
        }
    }

    return 0;
}