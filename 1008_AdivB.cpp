#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    double ans = (double)a / (double)b;

    printf("%.10f", ans);

    return 0;
}