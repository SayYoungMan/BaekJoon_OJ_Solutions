#include <iostream>

int main() {
    int n;

    std::cin >> n;

    for (int i=1; i <= 9; i++) {
        printf("%i * %i = %i\n", n, i, n*i);
    }

    return 0;

}