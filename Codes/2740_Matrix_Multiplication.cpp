#include <iostream>
#include <vector>

std::vector< std::vector<int> > A;
std::vector< std::vector<int> > B;

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, m, k, num;

    std::cin >> n >> m;

    // Make A
    for (int i=0; i < n; i++) {
        std::vector<int> row;
        for (int j=0; j < m; j++) {
            std::cin >> num;
            row.push_back(num);
        }
        A.push_back(row);
    }

    std::cin >> m >> k;
    // Make B
    for (int i=0; i < m; i++) {
        std::vector<int> row;
        for (int j=0; j < k; j++) {
            std::cin >> num;
            row.push_back(num);
        }
        B.push_back(row);
    }

    std::vector< std::vector<int> > ans(n, std::vector<int>(k, 0));

    for (int i=0; i < n; i++) {
        for (int j=0; j < k; j++) {
            for (int cur=0; cur < m; cur++) {
                ans[i][j] += (A[i][cur] * B[cur][j]);
            }
        }
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < k; j++) { 
            std::cout << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}