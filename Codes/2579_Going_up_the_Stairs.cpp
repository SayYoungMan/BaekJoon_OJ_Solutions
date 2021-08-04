#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_STAIRS 300

std::vector<std::vector<int>> points (MAX_STAIRS + 5, std::vector<int>(2, 0));

int main() {
    int n, point;

    std::cin >> n;
    std::cin >> point;
    
    if (n == 1) {
        std::cout << point;
        return 0;
    }

    points[1][0] = point;

    for (int i=2; i <= n; i++) {
        std::cin >> point;

        points[i][0] = std::max({ points[i-2][0] + point, points[i-2][1] + point });
        points[i][1] = points[i-1][0] + point;
    }

    std::cout << std::max({ points[n][0], points[n][1] });

    return 0;
}