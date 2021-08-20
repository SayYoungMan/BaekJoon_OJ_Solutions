#include <iostream>

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
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int t, a, b;
    std::cin >> t;
    for (int i=0; i < t; i++) {
        std::cin >> a >> b;
        std::cout << LCM(a, b) << '\n';
    }

    return 0;
}