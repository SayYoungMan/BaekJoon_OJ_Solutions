#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, age;
    std::string name;
    std::vector<std::pair<int, std::string>> people;

    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::cin >> age >> name;

        people.push_back(std::make_pair(age, name));
    }

    std::stable_sort(people.begin(), people.end(), [](auto &left, auto &right) {
        return left.first < right.first;
    });

    for (auto &p: people) std::cout << p.first << ' ' << p.second << '\n';

    return 0;
}