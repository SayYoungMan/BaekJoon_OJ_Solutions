#include <iostream>
#include <math.h>

int main() {
    int t, h, w, n, floor, room;

    std::cin >> t;

    for (int i=0; i<t; i++) {
        std::cin >> h >> w >> n;

        room = ceil((float)n / (float)h);
        floor = (n % h) ? n % h : h;

        if (room < 10) {
            printf("%i0%i\n", floor, room);
        } else {
            printf("%i%i\n", floor, room);
        }
    }

    return 0;
}