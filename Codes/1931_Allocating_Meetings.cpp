#include <iostream>
#include <vector>
#include <algorithm>

bool sortSec(std::pair<int, int> &a, std::pair<int, int> &b) {
    if (a.second == b.second) {
        return (a.first < b.first);
    }
    else return (a.second < b.second);
}

int main() {
    int n, start, end;
    std::vector<std::pair<int, int>> meetings;

    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::cin >> start >> end;
        meetings.push_back(std::make_pair(start, end));
    }

    std::sort(meetings.begin(), meetings.end(), sortSec);

    // std::cout << "Sorted vector: \n";
    // for (int i=0; i < n; i++) {
    //     std::cout << meetings[i].first << " " << meetings[i].second << '\n';
    // }

    int i = 0, time = 0, ans = 0;
    while (i < n) {
        if (time <= meetings[i].first) {
            time = meetings[i].second;
            ans++;
            i++;
        } else {
            i++;
        }
    }

    std::cout << ans;

    return 0;
}