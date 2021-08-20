#include <iostream>
#include <stack>

int main() {
    int k, num;
    std::stack<int> st;
    std::cin >> k;

    for (int i=0; i < k; i++) {
        std::cin >> num;

        if (num == 0) st.pop();
        else st.push(num);
    }

    int sum = 0;
    while (st.size() > 0) {
        sum += st.top();
        st.pop();
    }

    std::cout << sum;
    
    return 0;
}