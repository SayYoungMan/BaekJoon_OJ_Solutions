#include <iostream>
#include <vector>
#include <algorithm>

struct Coord {
    int x;
    int y;
} c;

bool compareCoord( const Coord &c1, const Coord &c2 ){
    if( c1.y != c2.y) return (c1.y < c2.y);
    else return (c1.x < c2.x);
}

int main() {
    int n, x, y;
    std::vector<Coord> coords;
    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::cin >> x >> y;
        c.x = x;
        c.y = y;

        coords.push_back(c);
    }

    std::sort(coords.begin(), coords.end(), compareCoord);
    for (const auto &c : coords) {
        std::cout << c.x << ' ' << c.y << '\n';
    }

    return 0;
}