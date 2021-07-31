#include <iostream>
#include <math.h>

int main() {
    int a, b, c;
    long int bep;

    std::cin >> a >> b >> c;

    if (b >= c) std::cout << -1;
    else  {
        bep = ceil((double)(a+1) / (double)(c-b));
        std::cout << bep;
    }
    return 0;
}