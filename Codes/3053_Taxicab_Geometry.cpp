#include <iostream>
#include <cmath>

int main() {
    double r;
    const double PI = std::acos(-1);

    std::cin >> r;

    printf("%.6f\n", r*r*PI);
    printf("%.6f\n", r*r*2.0);

    return 0;
}