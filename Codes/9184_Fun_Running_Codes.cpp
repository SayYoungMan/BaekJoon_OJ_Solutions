#include <iostream>
#include <vector>

std::vector<std::vector<std::vector<int>>> w(21, std::vector<std::vector<int>> (21, std::vector<int> (21, -1)));

int func(int a, int b, int c) {
    int ans;

    if (a <= 0 || b <= 0 || c <= 0) return 1;

    else if (a > 20 || b > 20 || c > 20) return func(20, 20, 20);

    else if (w[a][b][c] != -1) return w[a][b][c];

    else if (a < b && b < c) {
        ans = func(a, b, c-1) + func(a, b-1, c-1) - func(a, b-1, c);
        w[a][b][c] = ans;
        return ans;
    }

    else {
        ans = func(a-1, b, c) + func(a-1, b-1, c) + func(a-1, b, c-1) - func(a-1, b-1, c-1);
        w[a][b][c] = ans;
        return ans;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c, ans = 0;

    while (true) {
        std::cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) break;

        ans = func(a, b, c);

        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
    }

    return 0;
}