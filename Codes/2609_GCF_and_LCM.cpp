#include <iostream>
#include <vector>
#include <algorithm>

int GCF(int a, int b) {
    int i = 1, gcf = 0;
    while (i <= a || i <= b) {
        if (a % i == 0 && b % i == 0) {
            gcf = std::max(i, gcf);
        }
        i++;
    }

    return gcf;
}

int LCM(int a, int b) {
    int i = a, j = b;
    while (i != j) {
        if (i < j) i += a;
        else j += b;
        // std::cout << i << '\n';
        // std::cout << j << '\n';
    }

    return i;
}

int main() {
    int a, b;
    std::cin >> a >> b;

    std::cout << GCF(a, b) << '\n';
    std::cout << LCM(a, b) << '\n';

    return 0;
}