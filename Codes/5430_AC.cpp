#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(std::string str, char delim) {
    std::vector<std::string> rv;
    std::istringstream ss(str);
    std::string token;

    while(std::getline(ss, token, delim)) rv.push_back(token);

    return rv;
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int t, n, num;
    std::string p;
    std::string line;

    std::cin >> t;
    for (int _=0; _ < t; _++) {
        std::deque<int> dq;

        std::cin >> p;
        std::cin >> n;
        std::cin >> line;

        bool rev = false;
        bool error = false;

        line = line.substr(1, line.size()-2);
        std::vector<std::string> nums;
        nums = split(line, ',');
        for (auto &i: nums) dq.push_back(std::stoi(i));

        for (auto &c: p) {
            if (c == 'R') rev = !rev;
            else if(c == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                else if (rev) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (error) std::cout << "error\n";
        else if (rev) {
            std::cout << '[';
            n = dq.size();
            for(int i=1; i < n; i++) {
                std::cout << dq.back() << ',';
                dq.pop_back();
            }
            if (!dq.empty()) std::cout << dq.back() << "]\n";
            else std::cout << "]\n";
        }
        else {
            std::cout << '[';
            n = dq.size();
            for(int i=1; i < n; i++) {
                std::cout << dq.front() << ',';
                dq.pop_front();
            }
            if (!dq.empty()) std::cout << dq.front() << "]\n";
            else std::cout << "]\n";
        }
    }

    return 0;
}