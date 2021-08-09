#include <iostream>
#include <stack>
#include <vector>

int main() {
    int n, num;
    std::stack<int> st;
    std::vector<char> res;

    std::cin >> n;

    int i = 1; // Next no. to be pushed
    for (int _ = 0; _ < n; _++) {
        std::cin >> num;

        if (!st.empty() && st.top() == num) {
            res.push_back('-');
            st.pop();
        }

        else if (i <= num) {
            while (i <= num) {
                res.push_back('+');
                st.push(i);
                i++;
            }
            res.push_back('-');
            st.pop();
        }

        else {
            std::cout << "NO";
            return 0;
        }
    }

    for (const auto &c: res) {
        std::cout << c << '\n';
    }

    return 0;
}