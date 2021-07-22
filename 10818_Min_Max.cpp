#include <iostream>

int main() {
    int min = 1000001, max = -1000001;

    int n, num;

    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::cin >> num;
        
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

    printf("%i %i", min, max);

    return 0;
}