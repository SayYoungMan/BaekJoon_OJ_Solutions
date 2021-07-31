#include <iostream>
#include <set>

int main() {
    std::set<int> ans;
    int num;

    for (int i=0; i<10; i++) {
        std::cin >> num;
        ans.insert(num % 42);
    }

    std::cout << ans.size();

    return 0;
}