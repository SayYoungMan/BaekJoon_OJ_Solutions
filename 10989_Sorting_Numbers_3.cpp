#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, num;
    std::cin >> n;
    std::vector<int> nums(10005, 0);

    for (int i = 0; i < n; i++) {
        std::cin >> num;

        nums[num]++;
    }

    for (int i = 1; i <= 10000; i++) {
        num = nums[i];
        for (int j = 0; j < num; j++) std::cout << i << '\n';
    }

    return 0;
}