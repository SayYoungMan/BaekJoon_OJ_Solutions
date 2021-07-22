#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, maxNum = -1;
    float sum = 0;

    std::cin >> n;

    std::vector<int> nums(n);

    for (int i=0; i<n; i++) {
        std::cin >> nums[i];
    }

    maxNum = *std::max_element(nums.begin(), nums.end());

    for (int i=0; i<n; i++) {
        sum += ((float)nums[i] / (float)maxNum) * 100;
    }

    printf("%.3f", (float)sum / (float)n);

    return 0;
}