#include <iostream>
#include <deque>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, x;
    std::deque<int> dq;
    std::string com;

    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::cin >> com;

        if (com == "push_back") {
            std::cin >> x;
            dq.push_back(x);
        }

        else if (com == "push_front") {
            std::cin >> x;
            dq.push_front(x);
        }

        else if (com == "pop_front") {
            if (dq.size() == 0) std::cout << -1 << '\n';
            else {
                std::cout << dq.front() << '\n';
                dq.pop_front();
            }
        }

        else if (com == "pop_back") {
            if (dq.size() == 0) std::cout << -1 << '\n';
            else {
                std::cout << dq.back() << '\n';
                dq.pop_back();
            }
        }

        else if (com == "size") std::cout << dq.size() << '\n';

        else if (com == "empty") {
            if (dq.empty()) std::cout << 1 << '\n';
            else std::cout << 0 << '\n';
        }

        else if (com == "front") {
            if (dq.empty()) std::cout << -1 << '\n';
            else std::cout << dq.front() << '\n';
        }

        else if (com == "back") {
            if (dq.empty()) std::cout << -1 << '\n';
            else std::cout << dq.back() << '\n';
        }
    }

    return 0;
}