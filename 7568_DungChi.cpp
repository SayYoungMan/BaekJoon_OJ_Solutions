#include <iostream>
#include <vector>

int main() {
    int n, h, w, ans;
    std::vector<int> heights, weights;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    for (int i=0; i<n; i++) {
        std::cin >> h >> w;

        heights.push_back(h);
        weights.push_back(w);
    }

    for (int i=0; i<n; i++) {
        ans = 1;
        for (int j=0; j<n; j++) {
            if (i == j) continue;

            if (heights[i] < heights[j] && weights[i] < weights[j]) ans++;
        }

        std::cout << ans << ' ';
    }

    return 0;

}