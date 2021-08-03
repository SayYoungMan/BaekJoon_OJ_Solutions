#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_TRIANGLE_SIZE 500

std::vector<std::vector<int>> sums (MAX_TRIANGLE_SIZE + 5, std::vector<int>(MAX_TRIANGLE_SIZE + 5, 0));

int main() {
    int n, num, ans = 0;

    std::cin >> n;

    for (int row=1; row <= n; row++) {
        for (int col=1; col <= row; col++) {
            std::cin >> num;

            // std::cout << num << ": " << std::max({ sums[row-1][col-1] + num, sums[row-1][col] + num }) << '\n';
            sums[row][col] = std::max({ sums[row-1][col-1] + num, sums[row-1][col] + num });
        }
    }

    for (int i=0; i <= n; i++) {
        ans = std::max({ ans, sums[n][i] });
    }

    std::cout << ans;

    return 0;
}