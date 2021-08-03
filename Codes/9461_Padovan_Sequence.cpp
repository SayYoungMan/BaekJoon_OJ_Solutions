#include <iostream>
#include <vector>

#define MAX_N 100

std::vector<long long int> P (MAX_N + 5, 0);

long long int func(int n) {
    if (P[n] != 0) return P[n];
    else {
        long long int ans = func(n-1) + func(n-5);
        P[n] = ans;
        return ans;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t, n;
    long long int ans;

    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;

    std::cin >> t;
    for (int i=0; i < t; i++) {
        std::cin >> n;
        ans = func(n);
        std::cout << ans << '\n';
    }

    return 0;
}