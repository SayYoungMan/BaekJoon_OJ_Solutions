#include <iostream>

int isPrime(int num) {
    if (num == 1) return false;
    for (int i=2; i < num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int m, n, sum = 0, min = -1;

    std::cin >> m >> n;

    for (int i=m; i <= n; i++) {
        if (isPrime(i)) {
            if (min < 0) {
                min = i;
            }
            sum += i;
        }
    }

    if (sum != 0) {
        std::cout << sum << std::endl;
        std::cout << min << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}