#include <iostream>

int main() {
    int h, m;

    std::cin >> h >> m;

    m -= 45;
    
    if (m < 0) {
        h -= 1;
        m = m + 60;
    }

    if (h < 0) {
        h += 24;
    }

    printf ("%i %i", h, m);

    return 0;
}