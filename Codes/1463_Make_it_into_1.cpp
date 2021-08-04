#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000000

std::vector<int> least (MAX_N + 5);

int main() {
    int n, ans = 0;

    std::cin >> n;

    for (int i = 1; i <= MAX_N; i++) {
        least[i] = i - 1;
    }

    for (int i = 3; i <= MAX_N; i++) {
        if (i % 6 == 0) {
            least[i] = std::min({ least[i/3], least[i/2], least[i-1] }) + 1;
        } else if (i % 3 == 0) {
            least[i] = std::min({ least[i/3], least[i-1] }) + 1;
        } else if (i % 2 == 0) {
            least[i] = std::min({ least[i/2], least[i-1] }) + 1;
        } else {
            least[i] = least[i-1] + 1;
        }
    }

    std::cout << least[n];

    return 0;
}