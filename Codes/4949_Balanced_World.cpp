#include <iostream>
#include <stack>
#include <string>

bool vps(std::string str) {
    std::stack<char> st;

    for (const auto &ch: str) {
        if (ch == '(') st.push('(');
        else if (ch == ')') {
            if (st.empty()) return false;
            else if (st.top() == '(') st.pop();
            else return false;
        }

        else if (ch == '[') st.push('[');
        else if (ch == ']') {
            if (st.empty()) return false;
            else if (st.top() == '[') st.pop();
            else return false;
        }
        else continue;
    }

    if (st.empty()) return true;
    else return false;

}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::string line;

    while (true) {
        std::getline(std::cin, line);

        if (line == ".") break;

        if (vps(line)) std::cout << "yes\n";
        else std::cout << "no\n";
    }

    return 0;
}