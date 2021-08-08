#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

int gcd(int a, int b) { return (a == 0) ? b : gcd(b % a, a); }

std::vector<int> factors(int n) {
    std::vector<int> fac;
    for (int i=2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            fac.push_back(i);
            if (i*i != n) fac.push_back(n / i);
        }
    }

    std::sort(fac.begin(), fac.end());

    fac.push_back(n);

    return fac;
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, num;
    std::cin >> n;

    std::vector<int> nums;
    std::unordered_set<int> diff;

    for (int i = 0; i < n; i++) {
        std::cin >> num;

        for (const auto &j : nums) {
            if (j == num) diff.insert(num);
            else diff.insert(abs(j - num));
        }

        nums.push_back(num);
    }

    while (diff.size() > 1)
    {
        int a = *diff.begin();
        diff.erase(a);
        int b = *diff.begin();
        diff.erase(b);
        diff.insert(gcd(a, b));
    }

    std::vector<int> ans = factors(*diff.begin());

    for (const auto &i: ans) std::cout << i << " ";

    return 0;
}