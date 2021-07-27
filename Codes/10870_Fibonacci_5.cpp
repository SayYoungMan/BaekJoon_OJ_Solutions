#include <iostream>

int fibonacci(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n-2) + fibonacci(n-1);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fibonacci(n);
}