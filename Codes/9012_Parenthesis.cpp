#include <iostream>
#include <stack>
#include <string>

bool vps(std::string str) {
    std::stack<char> st;

    for (const auto &ch: str) {
        if (ch == '(') st.push('(');
        else if (ch == ')') {
            if (st.empty()) return false;
            else st.pop();
        }
    }

    if (st.empty()) return true;
    else return false;

}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int t;
    std::string str;

    std::cin >> t;

    for (int i=0; i < t; i++) {
        std::cin >> str;
        if (vps(str)) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}