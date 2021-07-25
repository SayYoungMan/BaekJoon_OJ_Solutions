#include <iostream>

int main() {
    int n, big, small, tmp;

    std::cin >> n;

    big += n / 5;
    while (big >= 0) {
        tmp = n - (big * 5);
        if (tmp % 3 == 0) {
            std::cout << big + (tmp / 3);
            return 0;
        } else {
            big -= 1;
        }
    }

    std::cout << -1;

    return 0;
}