#include <iostream>
#include <set>
#include <vector>

void backTrack(std::vector<int> cur, int n, int m) {

    // If satisfied
    if (cur.size() == m) {
        for (int &i: cur) std::cout << i << ' ';
        std::cout << '\n';
        return;
    }

    // If still requires further search
    for (int i=1; i <= n; i++) {
        std::vector<int> tmp = cur;
        tmp.push_back(i);
        backTrack(tmp, n, m);
    }

    return;
}

int main() {
    int n, m;
    std::vector<int> cur;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    backTrack(cur, n, m);

    return 0;
}