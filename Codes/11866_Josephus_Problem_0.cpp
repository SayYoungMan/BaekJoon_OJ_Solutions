#include <iostream>
#include <queue>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::queue<int> q;
    int n, k;

    std::cin >> n >> k;

    
    std::cout << '<';

    for (int i=1; i <= n; i++) q.push(i);

    while(q.size() > 1) {
        int rem = k;

        while(rem-- > 1) {
            q.push(q.front());
            q.pop();
        }
        std::cout << q.front() << ", ";
        q.pop();
    }
    std::cout << q.front() << '>';

    return 0;
}