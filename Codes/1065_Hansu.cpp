#include <iostream>

bool checkHansu(int num) {
    if (num < 100) {
        return true;
    } else if (num == 1000) {
        return false;
    } else {
        int a, b, c;

        c = num % 10;
        num /= 10;
        b = num % 10;
        num /= 10;
        a = num;

        return (a - b) == (b - c);
    }
}

int main() {
    int n, ans = 0;

    std::cin >> n;

    for (int i=1; i <= n; i++) {
        if (checkHansu(i)) {
            ans += 1;
        }
    }

    std::cout << ans;

    return 0;
}