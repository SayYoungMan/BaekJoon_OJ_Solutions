#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100
#define MAX_K 100000

std::vector<int> W (MAX_N + 5, 0);
std::vector<int> V (MAX_N + 5, 0);
std::vector<std::vector<int>> dp (MAX_N + 5, std::vector<int>(MAX_K + 5, -1));

int ks(int n, int k) {
    int res;

    // If already visited, return the value
    if (dp[n][k] != -1) return dp[n][k];

    // Base case
    if (n == 0 || k == 0) res = 0;

    // If heavier than remaining capacity move to the next item
    else if (W[n] > k) res = ks(n-1, k);

    // Else, consider both case of choosing and not choosing this item and return the bigger of it
    else res = std::max(ks(n-1, k), ks(n-1, k-W[n]) + V[n]);

    dp[n][k] = res;

    return res;
}

int main() {
    int n, k, w, v;

    std::cin >> n >> k;

    for (int i=1; i <= n; i++) {
        std::cin >> w >> v;
        W[i] = w;
        V[i] = v;
    }

    int ans = ks(n, k);

    std::cout << ans;

    return 0;
}