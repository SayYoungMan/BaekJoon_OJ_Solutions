#include <iostream>

int main() {
    long int n, sum, tmp;
    std::cin >> n;

    for (long int i = 1; i<n; i++) {
        tmp = i;
        sum = i;

        while(tmp > 10) {
            sum += tmp % 10;
            tmp /= 10;
        }
        sum += tmp;

        if (sum == n) {
            std::cout << i;
            return 0;
        }
    }

    std::cout << '0';
    return 0;
}