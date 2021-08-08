#include <iostream>
#include <algorithm>

// Can solve in O(log n) time
int legendre(int n, int v) {
    int div;
    int res = 0;
    while (n >= v) {
        div = n / v;
        res += div;
        n = div;
    }

    return res;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    int up_five = legendre(n, 5);
    int up_two = legendre(n, 2);

    // std::cout << up_five << '\n';

    int down_five = legendre(m, 5);
    int down_two = legendre(m, 2);

    down_five += legendre(n-m, 5);
    down_two += legendre(n-m, 2);

    int total_five = up_five - down_five;
    int total_two = up_two - down_two;

    std::cout << std::min(total_five, total_two);
}