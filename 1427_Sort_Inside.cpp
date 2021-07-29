#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long int n;
    std::vector<int> arr;

    std::cin >> n;

    while (n > 0) {
        arr.push_back(n%10);
        n /= 10;
    }

    std::sort(arr.rbegin(), arr.rend());

    for (auto &digit : arr) std::cout << digit;

    return 0;
}