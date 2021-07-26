#include <iostream>
#include <vector>

int main() {
    int m, n;

    std::cin >> m >> n;

    std::vector<bool> nums(n+1);

    // Set all vector value to true
    std::fill(nums.begin(), nums.end(), true);

    nums[1] = false;

    for (int i=2; i*i <= n; i++) {
        if (nums[i] == true) {
            for (int j = i*i; j <= n; j+=i) nums[j] = false;
        }
    }

    for (int i=m; i <= n; i++) {
        if (nums[i] == true) std::cout << i << '\n';
    }

    return 0;
}