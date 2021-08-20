#include <iostream>

int factorial(int n) {
    int ans = 1;
    for (int i=2; i <= n; i++) ans *= i;
    return ans;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::cout << factorial(n) / (factorial(k) * factorial(n-k));

    return 0;
}