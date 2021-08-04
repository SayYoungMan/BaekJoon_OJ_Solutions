#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000

std::vector<int> nums (MAX_N + 5, 0);
std::vector<int> lis (MAX_N + 5, 1);
std::vector<int> lds (MAX_N + 5, 1);

int main() {
    int n;

    std::cin >> n;

    for (int i=0; i < n; i++) std::cin >> nums[i];

    for (int i=1; i < n; i++) {
        for (int j=0; j < i; j++) {
            if (nums[i] > nums[j]) lis[i] = std::max(lis[i], lis[j] + 1);
        }
    }

    for (int i=n-2; i >= 0; i--) {
        for (int j=n-1; j > i; j--) {
            if (nums[i] > nums[j]) lds[i] = std::max(lds[i], lds[j] + 1);
        }
    }

    // std::cout << "lis: ";
    // for (int i=0; i < n; i++) std::cout << lis[i] << " ";
    // std::cout << "\nlds: ";
    // for (int i=0; i < n; i++) std::cout << lds[i] << " ";

    int max = 0;
    for (int i=0; i < n; i++) {
        max = std::max(lis[i] + lds[i] - 1, max);
    }

    std::cout << max;

    return 0;
}