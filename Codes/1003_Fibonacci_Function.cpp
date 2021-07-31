#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t, n;
    std::cin >> t;
    for (int i=0; i<t; i++) {
        std::cin >> n;
        std::vector<int> zeroCalls (n+5, 0);
        std::vector<int> oneCalls (n+5, 0);

        zeroCalls[0] = 1;
        oneCalls[1] = 1;

        for (int i=2; i <= n; i++) {
            zeroCalls[i] = zeroCalls[i-1] + zeroCalls[i-2];
            oneCalls[i] = oneCalls[i-1] + oneCalls[i-2];
        }

        std::cout << zeroCalls[n] << ' ' << oneCalls[n] << '\n';
    }

    return 0;
}
