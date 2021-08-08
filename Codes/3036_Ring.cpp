#include <iostream>

int gcd(int a, int b) { return (a == 0) ? b : gcd(b % a, a); }

int main() {
    int n, f, num, g;
    std::cin >> n;
    std::cin >> f;

    for (int i=0; i < n-1; i++) {
        std::cin >> num;
        g = gcd(num, f);
        std::cout << f / g << '/' << num / g << '\n';
    }

    return 0;
}