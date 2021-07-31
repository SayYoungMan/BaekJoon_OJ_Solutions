#include <iostream>
#include <set>
#include <vector>

std::set<std::vector<int>> soln;
std::set<std::vector<int>> visited;

bool isValid(std::vector<int> cur) {
    // Checks if there is no duplicate in the combination cur which makes it invalid

    std::set<int> tmp;
    
    for (auto &i: cur) tmp.insert(i);

    return (tmp.size() == cur.size());
}

void printSoln() {
    for (auto &s: soln) {
        for (auto &i: s) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }

    return;
}

void backTrack(std::vector<int> cur, int n, int m) {
    // If visited return
    if (visited.find(cur) != visited.end()) return;
    else visited.insert(cur);

    // If invalid return
    if (!isValid(cur)) return;

    // If satisfied
    if (cur.size() == m) {
        soln.insert(cur);
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

    std::cin >> n >> m;

    backTrack(cur, n, m);

    printSoln();

    return 0;
}