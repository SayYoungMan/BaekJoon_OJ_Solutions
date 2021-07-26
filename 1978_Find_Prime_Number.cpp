#include <iostream>

int isPrime(int num) {
    if (num == 1) return false;
    for (int i=2; i < num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, num, ans = 0;

    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::cin >> num;
        if (isPrime(num)) ans++;
    }

    std::cout << ans;

    return 0;
}