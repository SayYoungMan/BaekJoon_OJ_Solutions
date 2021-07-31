#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<std::vector<int>> stat (20, std::vector<int> (20));
int diff = std::numeric_limits<int>::max();
int n;

void backTrack(int cur, std::vector<int>start, std::vector<int>link, int startStat, int linkStat) {
    // If all players assigned
    if (start.size() == n/2 && link.size() == n/2) {
        diff = std::min(diff, abs(startStat - linkStat));
        if (diff == 0) {
            std::cout << 0;
            exit(0);
        }
        return;
    }

    // If Team unbalanced return;
    if (start.size() > n/2 || link.size() > n/2) return;

    // Place cur in start
    start.push_back(cur);
    int tmp = startStat;
    for (auto &i : start) {
        tmp += (stat[i][cur] + stat[cur][i]);
    }
    backTrack(cur+1, start, link, tmp, linkStat);

    // Initialise
    start.pop_back();

    // Place cur in link
    link.push_back(cur);
    tmp = linkStat;
    for (auto &i : link) {
        tmp += (stat[i][cur] + stat[cur][i]);
    }
    backTrack(cur+1, start, link, startStat, tmp);

    return;
}

int main() {
    std::vector<int> start;
    std::vector<int> link;

    std::cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int num;
            std::cin >> num;
            stat[i][j] = num;
        }
    }

    backTrack(0, start, link, 0, 0);

    std::cout << diff;

    return 0;
}
