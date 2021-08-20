#include <iostream>
#include <vector>
#include <string>

class stack {
    public:
        int size = 0;
        std::vector<int> list;
    
    void push(int x) {
        list.push_back(x);
        size++;
    }

    void empty() {
        if (size == 0) {
            std::cout << 1 << '\n';
        }
        else {
            std::cout << 0 << '\n';
        }
    }

    void pop() {
        if (size == 0) {
            std::cout << -1 << '\n';
        }
        else {
            std::cout << list[size-1] << '\n';
            list.pop_back();
            size--;
        }
    }

    void _size() {
        std::cout << size << '\n';
    }

    void top() {
        if (size == 0) {
            std::cout << -1 << '\n';
        }
        else {
            std::cout << list[size-1] << '\n';
        }
    }
};

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    stack st;
    int n, num;
    std::string command;

    std::cin >> n;
    for (int i=0; i < n; i++) {
        std::cin >> command;

        if (command == "push") {
            std::cin >> num;
            st.push(num);
        }
        else if (command == "top") st.top();
        else if (command == "size") st._size();
        else if (command == "empty") st.empty();
        else if (command == "pop") st.pop();
    }

    return 0;
}