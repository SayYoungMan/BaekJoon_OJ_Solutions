#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n, m, card;
    int ans, diff = std::numeric_limits<int>::max(), tmp;
    std::vector<int> cards;

    std::cin >> n >> m;

    for (int i=0; i < n; i++) {
        std::cin >> card;
        cards.push_back(card);
    }

    for (int i=0; i < n-2; i++) {
        for (int j=i+1; j < n-1; j++) {
            for (int k=j+1; k < n; k++) {
                tmp = cards[i] + cards[j] + cards[k];
                if (m - tmp < diff && m - tmp >= 0) {
                    diff = m - tmp;
                    ans = tmp;
                }
            }
        }
    }

    std::cout << ans;

    return 0;
}