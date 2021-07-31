#include <iostream>

int main() {
    int t, a, b;

    std::cin >> t;

    for (int i=1; i <= t; i++) {
        std::cin >> a >> b;

        printf("Case #%i: %i + %i = %i\n", i, a, b, a+b);
    }

    return 0;
}