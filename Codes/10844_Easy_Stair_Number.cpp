#include <iostream>
#include <vector>

std::vector<std::vector<long long int>> nums (105, std::vector<long long int>(10, 0));

int main() {
    for (int i=1; i <= 9; i++) {
        nums[1][i] = 1;
    }

    int n;
    long long int sum = 0;
    std::cin >> n;

    for (int i=2; i <= n; i++) {
        // X0 only possible if X=1
        nums[i][0] = nums[i-1][1] % 1000000000;
        // From 1 to 8 it can be made of i-1 and i+1
        for (int j=1; j < 9; j++) nums[i][j] = (nums[i-1][j-1] % 1000000000) + (nums[i-1][j+1] % 1000000000);
        // X9 only possible if X=8
        nums[i][9] = nums[i-1][8] % 1000000000;
    }

    for (int i=0; i < 10; i++) (sum += nums[n][i] % 1000000000);

    std::cout << sum % 1000000000;

    return 0;
}