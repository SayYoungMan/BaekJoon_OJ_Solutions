#include <iostream>
#include <algorithm>

std::pair<int, int> twos_and_fives (int n) {
    if (n == 0) return std::make_pair(0, 0);

    auto pair = twos_and_fives(n-1);

    while (n % 2 == 0 || n % 5 == 0) {
        if (n % 2 == 0) {
            pair.first++;
            n /= 2;
        }
        if (n % 5 == 0) {
            pair.second++;
            n /= 5;
        }
    }
    
    return pair;
}

int main() {
    int n;
    std::cin >> n;

    std::pair<int, int> res = twos_and_fives(n);
    std::cout << std::min(res.first, res.second);

    return 0;
}