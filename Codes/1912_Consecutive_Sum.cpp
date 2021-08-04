#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

std::vector<int> nums (MAX_N + 5, 0);

int main() {
    int n, front = 0, end = 0;

    std::cin >> n;

    for (int i=0; i < n; i++) std::cin >> nums[i];

    int ans = nums[0];
    int cur_max = nums[0];

    for (int i=1; i < n; i++) {
        cur_max = std::max(cur_max + nums[i], nums[i]);
        // std::cout << cur_max << '\n';
        ans = std::max(cur_max, ans);
    }

    std::cout << ans;

    return 0;
}