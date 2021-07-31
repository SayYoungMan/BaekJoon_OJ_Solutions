#include <iostream>

int main() {
    int n;
    std::cin >> n;

    
    while (n > 1) {
        int fac = 2;
        while (fac <= n) {
            if (n % fac == 0) {
                n /= fac;
                std::cout << fac << std::endl;
                break;
            }
            fac++;
        }
    }

    return 0;
}