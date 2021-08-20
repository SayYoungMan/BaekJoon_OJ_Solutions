#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, num;
    std::vector<int> P;

    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::cin >> num;
        P.push_back(num);
    }

    std::sort(P.begin(), P.end());

    // for (int i=0; i < n; i++) std::cout << P[i];

    int cur_sum = 0;
    long long int ans = 0;
    for (int i=0; i < n; i++) {
        cur_sum += P[i];
        ans += cur_sum;
    }

    std::cout << ans;

    return 0;
}