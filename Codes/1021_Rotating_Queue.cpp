#include <iostream>
#include <deque>
#include <algorithm>

std::deque<int> rq;

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, m, num, ans = 0;
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        rq.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        std::cin >> num;

        // Find left
        std::deque<int> tmp = rq;
        int l = 0;
        while(tmp.front() != num) {
            tmp.push_back(tmp.front());
            tmp.pop_front();
            l++;
        }

        // Find right
        int r = 0;
        while(rq.front() != num) {
            rq.push_front(rq.back());
            rq.pop_back();
            r++;
        }

        rq.pop_front();

        // std::cout << "l: " << l << " r: " << r << '\n';

        ans += std::min(l, r);
    }

    std::cout << ans;
    
    return 0;
}