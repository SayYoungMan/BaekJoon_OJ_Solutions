#include <iostream>
#include <vector>

#define MAX_N 1000000

// P(1) = 1
// P(2) = 2
// P(3) = 3
// P(4) = 5
// P(5) = 8

std::vector<int> P (MAX_N + 5, 0);

int main() {
    int n;
    std::cin >> n;

    P[1] = 1;
    P[2] = 2;

    for (int i=3; i <= n; i++) {
        P[i] = P[i-1] % 15746 + P[i-2] % 15746;
    }

    std::cout << P[n] % 15746;

    return 0;

}