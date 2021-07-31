#include <iostream>

int main() {
    int n, ans = 1, thres = 1;

    std::cin >> n;

    while ( n > thres ) {
        thres += ans * 6;
        ans++;
    }

    std::cout << ans;

    return 0;
}