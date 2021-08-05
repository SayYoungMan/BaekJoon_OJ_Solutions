#include <iostream>
#include <vector>

#define MAX_N 10

std::vector<int> coins (MAX_N + 5, 0);

int main() {
    int n, k, ans = 0;

    std::cin >> n >> k;

    for(int i=0; i < n; i++) std::cin >> coins[i];

    while (k > 0) {
        int i = 0;
        if (k >= coins[n-1]) i = n;

        else {
            while (k >= coins[i]) {
                i++;
            }
        }

        int chosen = coins[i-1];

        ans += (k / chosen);
        k %= chosen;
    }

    std::cout << ans;

    return 0;
}