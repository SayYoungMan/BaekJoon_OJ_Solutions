#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_WINE 10000

std::vector<int> wines (MAX_WINE + 5, 0);
std::vector<int> dp (MAX_WINE + 5, 0);

int main() {
    int n, wine;

    std::cin >> n;

    for (int i=1; i<=n; i++) std::cin >> wines[i];

    // If n == 1:
    dp[1] = wines[1];
    if (n == 1) {
        std::cout << dp[1];
        return 0;
    }

    // If n == 2:
    dp[2] = wines[1] + wines[2];
    if (n == 2) {
        std::cout << dp[2];
        return 0;
    }

    // If n == 3:
    // OXO || XOO || OOX
    dp[3] = std::max({ wines[1] + wines[3], wines[2] + wines[3], dp[2] });

    // If n > 3:
    for (int i=4; i <= n; i++) {
        dp[i] = std::max({ dp[i-2] + wines[i], dp[i-3] + wines[i-1] + wines[i] });
        dp[i] = std::max({ dp[i-1], dp[i] });
    }

    std::cout << dp[n];

    return 0;
}