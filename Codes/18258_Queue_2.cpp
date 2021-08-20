#include <iostream>
#include <queue>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::queue<int> q;
    int n, x;
    std::string com;

    std::cin >> n;
    for (int i=0; i < n; i++) {
        std::cin >> com;

        if (com == "push") {
            std::cin >> x;
            q.push(x);
        }

        else if (com == "pop") {
            if (q.empty()) std::cout << -1 << '\n';
            else {
                std::cout << q.front() << '\n';
                q.pop();
            }
        }

        else if (com == "size") {
            std::cout << q.size() << '\n';
        }

        else if (com == "empty") {
            if (q.empty()) std::cout << 1 << '\n';
            else std::cout << 0 << '\n';
        }

        else if (com == "front") {
            if (q.empty()) std::cout << -1 << '\n';
            else {
                std::cout << q.front() << '\n';
            }
        }

        else if (com == "back") {
            if (q.empty()) std::cout << -1 << '\n';
            else {
                std::cout << q.back() << '\n';
            }
        }
    }

    return 0;
}