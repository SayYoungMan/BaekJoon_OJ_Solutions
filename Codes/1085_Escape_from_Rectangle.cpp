#include <iostream>
#include <algorithm>

int main() {
    int x, y, w, h, ans = 1001;

    std::cin >> x >> y >> w >> h;

    ans = std::min(ans, x);
    ans = std::min(ans, y);
    ans = std::min(ans, w-x);
    ans = std::min(ans, h-y);

    std::cout << ans;

    return 0;
}