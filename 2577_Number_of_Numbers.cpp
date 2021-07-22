#include <iostream>

int main() {
    int occ[10] = { 0 };
    int a, b, c;

    std::cin >> a >> b >> c;

    int prod = a * b * c;

    while (prod > 0) {
        occ[prod%10] += 1;
        prod /= 10;
    }

    for (int i=0; i < 10; i++) {
        std::cout << occ[i] << std::endl;
    }

    return 0;
}