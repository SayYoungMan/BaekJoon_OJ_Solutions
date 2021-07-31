#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<char>> overall;

int checkBoard(int t, int l) {
    int bwAns = 0;
    int wbAns = 0;

    // bwAns first
    for (int i=t; i < t+8; i++) {
        for (int j=l; j < l+8; j++) {
            // Odd rows
            if (i%2==1) {
                // Odd cols
                if (j%2==1 && overall[i][j] == 'W') bwAns++;
                // Even cols
                else if (j%2==0 && overall[i][j] == 'B') bwAns++;
            }

            // Even rows
            else if (i%2==0) {
                // Odd cols
                if (j%2==1 && overall[i][j] == 'B') bwAns++;
                // Even cols
                else if (j%2==0 && overall[i][j] == 'W') bwAns++;
            }
        }
    }

    // Then wbAns
    for (int i=t; i < t+8; i++) {
        for (int j=l; j < l+8; j++) {
            // Odd rows
            if (i%2==1) {
                // Odd cols
                if (j%2==1 && overall[i][j] == 'B') wbAns++;
                // Even cols
                else if (j%2==0 && overall[i][j] == 'W') wbAns++;
            }

            // Even rows
            else if (i%2==0) {
                // Odd cols
                if (j%2==1 && overall[i][j] == 'W') wbAns++;
                // Even cols
                else if (j%2==0 && overall[i][j] == 'B') wbAns++;
            }
        }
    }

    return std::min(bwAns, wbAns);
}

int main() {
    int n, m, tmpAns, ans = 65;
    char k;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    for (int i=0; i < n; i++) {
        std::vector<char> tmp;

        for (int j=0; j < m; j++) {
            std::cin >> k;
            tmp.push_back(k);
        }

        overall.push_back(tmp);
    }

    for (int i=0; i <= n-8; i++) {
        for (int j=0; j <= m-8; j++) {
            tmpAns = checkBoard(i, j);
            // std::cout << tmpAns << '\n';
            ans = std::min(tmpAns, ans);
        }
    }

    std::cout << ans;

    return 0;
}