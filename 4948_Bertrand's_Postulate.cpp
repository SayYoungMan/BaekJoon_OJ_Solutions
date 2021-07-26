#include <iostream>
#include <vector>

int che(int m, int n) {
    int ans = 0;

    std::vector<bool> nums(n+1);

    std::fill(nums.begin(), nums.end(), true);
    nums[1] = false;

    for (int i=2; i*i <= n; i++) {
        if (nums[i] == true) {
            for (int j = i*i; j <= n; j+=i) nums[j] = false;
        }
    }

    for (int i=m+1; i <= n; i++) {
        if (nums[i] == true) ans++;
    }

    return ans;
}

int main() {
    int n;

    while(true) {
        std::cin >> n;
        if (n == 0) break;

        std::cout << che(n, 2*n) << '\n';
    }

    return 0;
}