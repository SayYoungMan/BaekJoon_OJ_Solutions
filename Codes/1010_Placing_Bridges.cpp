#include <iostream>
#include <vector>

#define MAX_N 30

std::vector<std::vector<int>> dp (MAX_N + 5, std::vector<int>(MAX_N + 5, 0));

int binomial_coeff(int n, int k) {
    if (dp[n][k] != 0) return dp[n][k];

    if (k == 0 || n == k) return 1;
    
    else {
        int ans = (binomial_coeff(n-1, k) + binomial_coeff(n-1, k-1));
        dp[n][k] = ans;
        return ans;
    }
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int t, n, m;
    std::cin >> t;
    for (int i=0; i < t; i++) {
        std::cin >> n >> m;
        std::cout << binomial_coeff(m, n) << '\n';
    }
    return 0;
}