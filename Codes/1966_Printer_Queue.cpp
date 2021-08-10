#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int t, n, m;
    
    std::cin >> t;
    for (int _ = 0; _ < t; _++) {
        std::vector<int> imp (10, 0);
        std::queue< std::pair<int, int> > q;

        std::cin >> n >> m;

        for (int i=0; i < n; i++) {
            int im;
            std::cin >> im;
            q.push(std::make_pair(i, im));
            imp[im]++;
        }

        // for (auto &i: imp) std::cout << i << " ";

        int out = -1;
        int most_imp = 9;
        int turn = 0;
        while (out != m) {
            while (imp[most_imp] == 0) most_imp--;
            while (q.front().second != most_imp) {
                q.push(q.front());
                q.pop();
            }
            out = q.front().first;
            // std::cout << "Pop: <" << q.front().first << ", " << q.front().second << ">\n";
            q.pop();
            turn++;
            imp[most_imp]--;
        }

        std::cout << turn << '\n';
    }

    return 0;
}