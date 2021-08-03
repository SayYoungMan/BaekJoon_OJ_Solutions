#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_WINE 10000

std::vector<std::vector<int>> wines (MAX_WINE + 5, std::vector<int>(2, 0));

int main() {
    int n, wine;

    std::cin >> n;
    std::cin >> wine;
    
    if (n == 1) {
        std::cout << wine;
        return 0;
    }

    wines[1][0] = wine;

    for (int i=2; i <= n; i++) {
        std::cin >> wine;

        wines[i][0] = std::max({ wines[i-2][0] + wine, wines[i-2][1] + wine });
        wines[i][1] = wines[i-1][0] + wine;
    }

    std::cout << std::max({ wines[n-1][0], wines[n-1][1], wines[n][0], wines[n][1] });

    return 0;
}