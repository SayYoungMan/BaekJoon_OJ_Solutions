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
    int n, k, p = 1000000007;

    long long num = 1, denom = 1;

    std::cin >> n >> k;

    for (int i = n-k+1; i <= n; i++) num = (num * i) % p;

    for (int i = 1; i <= k; i++) denom = (denom * i) % p;

    std::cout << (num * pow(denom, p-2, p)) % p; // a^(p-2) = a^-1 (mod p)

    return 0;
}