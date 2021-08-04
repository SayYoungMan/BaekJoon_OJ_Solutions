#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> nums (1005, 0);
std::vector<int> lis (1005, 1);

int main() {
    int n;

    std::cin >> n;

    for (int i=0; i < n; i++) std::cin >> nums[i];

    for (int i=1; i < n; i++) {
        for (int j=0; j < i; j++) {
            if (nums[i] > nums[j]) lis[i] = std::max(lis[i], lis[j] + 1);
        }
    }

    std::cout << *std::max_element(lis.begin(), lis.end());

    return 0;
}