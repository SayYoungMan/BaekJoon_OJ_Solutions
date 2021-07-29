#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

bool compareWords(std::string s1, std::string s2) {
    if(s1.length() != s2.length()) return (s1.length() < s2.length());
    else return (s1 < s2);
}

int main() {
    int n;
    std::string w;
    std::cin >> n;

    std::vector<std::string> words;

    for (int i = 0; i < n; i++) {
        std::cin >> w;
        words.push_back(w);
    }

    std::unordered_set<std::string> s;
    for (auto &w : words) s.insert(w);
    words.assign(s.begin(), s.end());

    std::sort(words.begin(), words.end(), compareWords);

    for (const auto &w : words) std::cout << w << '\n';

    return 0;
}