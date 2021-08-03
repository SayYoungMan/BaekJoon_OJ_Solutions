#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000

std::vector<std::vector<int>> cost (MAX_N + 5, std::vector<int> (3, 0));

int main() {
    int n, r, g, b;

    std::cin >> n;
    std::cin >> r >> g >> b;

    cost[0][0] = r;
    cost[0][1] = g;
    cost[0][2] = b;

    for (int i=1; i < n; i++) {
        std::cin >> r >> g >> b;

        cost[i][0] = std::min({cost[i-1][1] + r, cost[i-1][2] + r});
        cost[i][1] = std::min({cost[i-1][0] + g, cost[i-1][2] + g});
        cost[i][2] = std::min({cost[i-1][0] + b, cost[i-1][1] + b});
    }

    std::cout << std::min({cost[n-1][0], cost[n-1][1], cost[n-1][2]});

    return 0;
}