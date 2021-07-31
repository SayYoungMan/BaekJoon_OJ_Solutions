#include <iostream>
#include <set>

std::set<std::set<int>> soln;
std::set<std::set<int>> visited;

void printSoln() {
    for (auto &s: soln) {
        for (auto &i: s) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }

    return;
}

void backTrack(std::set<int> cur, int n, int m) {
    // If visited return
    if (visited.find(cur) != visited.end()) return;
    else visited.insert(cur);

    // If satisfied
    if (cur.size() == m) {
        soln.insert(cur);
        return;
    }

    // If still requires further search
    for (int i=1; i <= n; i++) {
        std::set<int> tmp = cur;
        tmp.insert(i);
        backTrack(tmp, n, m);
    }

    return;
}

int main() {
    int n, m;
    std::set<int> cur;

    std::cin >> n >> m;

    backTrack(cur, n, m);

    printSoln();

    return 0;
}