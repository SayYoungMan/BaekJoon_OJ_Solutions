#include <iostream>
#include <vector>

#define MAX_N 1000

std::vector<std::vector<int>> dp (MAX_N + 5, std::vector<int>(MAX_N + 5, 0));

int binomial_coeff(int n, int k) {
    if (dp[n][k] != 0) return dp[n][k];

    if (k == 0 || n == k) return 1;
    
    else {
        int ans = (binomial_coeff(n-1, k) + binomial_coeff(n-1, k-1)) % 10007;
        dp[n][k] = ans;
        return ans;
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::cout << binomial_coeff(n, k);

    return 0;
}