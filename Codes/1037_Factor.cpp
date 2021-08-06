#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, ans, num;
    std::vector<int> factors;

    std::cin >> n;
    for (int i=0; i < n; i++) {
        std::cin >> num;
        factors.push_back(num);
    }

    std::sort(factors.begin(), factors.end());

    std::cout << factors[0] * factors[n-1];

    return 0;
}