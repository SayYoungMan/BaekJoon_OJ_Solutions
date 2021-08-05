#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(std::string line, char delim) {
    std::stringstream ss (line);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(ss, segment, delim)) {
        seglist.push_back(segment);
    }

    return seglist;
}

int main() {
    std::string line;
    std::cin >> line;

    std::vector<std::string> minus_removed = split(line, '-');
    std::vector<int> added;

    for (auto &s: minus_removed) {
        std::vector<std::string> plus_removed = split(s, '+');
        int sum = 0;
        for (auto &i: plus_removed) {
            sum += std::stoi(i);
        }
        added.push_back(sum);
    }

    int ans = added[0];
    for (int i=1; i < added.size(); i++) {
        ans -= added[i];
    }

    std::cout << ans;

    return 0;
}