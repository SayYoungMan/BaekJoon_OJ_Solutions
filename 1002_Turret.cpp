#include <iostream>
#include <cmath>

int main() {
    int t, x1, y1, r1, x2, y2, r2;
    double dist;

    std::cin >> t;

    for(int i = 0; i < t; i++) {
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        dist = std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        
        // For the case where the circles have the same centre
        if (x1 == x2 && y1 == y2) {
            // Exact same circles so infinite
            if (r1 == r2) std::cout << -1 << '\n';
            // Circles with same centre but different radius never meet
            else std::cout << 0 << '\n';
        }
        // For the case where the one circle lies within the other
        else if (r1 >= dist + (double)r2 || r2 >= dist + (double)r1) {
            // Does not meet if the difference between two radii is not same as the distance
            if (dist != std::abs(r1-r2)) std::cout << 0 << '\n';
            // If same meet at one point
            else std::cout << 1 << '\n';
        }

        // For the case where circles lie outside
        else {
            if (dist > (double)(r1 + r2)) std::cout << 0 << '\n';
            else if (dist == (double)(r1 + r2)) std::cout << 1 << '\n';
            else std::cout << 2 << '\n';
        }
    }

    return 0;
}