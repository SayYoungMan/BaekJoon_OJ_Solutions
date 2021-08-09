#include <iostream>
#include <stack>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, num;
    std::stack<std::pair<int, int> > st;
    
    std::cin >> n;

    std::vector<int> ans (n, -1);

    for (int i=0; i < n; i++) {
        std::cin >> num;
        while (!st.empty() && st.top().second < num) {
            ans[st.top().first] = num;
            st.pop();
        }
        st.push(std::make_pair(i, num));
    }

    for (int i=0; i < n; i++) {
        std::cout << ans[i] << ' ';
    }

    return 0;
}