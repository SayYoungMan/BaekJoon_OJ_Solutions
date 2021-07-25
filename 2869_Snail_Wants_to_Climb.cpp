#include <iostream>
#include <math.h>

int main() {
    long int a, b, v;

    std::cin >> a >> b >> v;

    std::cout << (long int) ceil((double)(v-b) / (double)(a-b));
}