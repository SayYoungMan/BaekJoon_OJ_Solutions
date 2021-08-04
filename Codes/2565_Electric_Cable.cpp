#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100
#define MAX_POS 500

std::vector<int> pos (MAX_POS + 5, -1);
std::vector<int> lis (MAX_POS + 5, 1);

int main() {
    int n, a, b;
    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::cin >> a >> b;
        pos[a] = b;
    }

    for (int i=2; i <= MAX_POS; i++) {
        if (pos[i] == -1) continue;

        for (int j=1; j < i; j++) {
            if (pos[j] == -1) continue;
            else if (pos[i] > pos[j]) lis[i] = std::max(lis[i], lis[j] + 1);
        }
    }

    // for (int i=1; i <= 7; i++) std::cout << lis[i] << '\n';

    int max = *std::max_element(lis.begin(), lis.end());
    std::cout << n - max;

    return 0;
}