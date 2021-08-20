#include <iostream>

long long pow(long long a, long long b, long long c) {
    if (b == 0) return 1;
    else if (b == 1) return a % c;

    long long res = pow(a, b / 2, c);
    if (b % 2)
        return ((res * a) % c * res) % c;
    else
        return (res * res) % c;
}

int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;

    std::cout << pow(a, b, c);

    return 0;
}