#include <iostream>
#include <vector>

long long sum(std::vector<int> &a) {
    long long ans = 0;

    for (int &num: a) {
        ans += num;
    }

    return ans;
}

int main() {
    std::vector<int> a { 1, 2, 3 };

    std::cout << sum(a);

    return 0;
}