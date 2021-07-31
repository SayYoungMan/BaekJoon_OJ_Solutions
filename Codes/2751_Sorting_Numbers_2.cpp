#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, num;
    
    std::cin >> n;
    std::vector<int> sorted;

    for(int i=0; i<n; i++) {
        std::cin >> num;
        sorted.push_back(num);
    }

    std::sort(sorted.begin(), sorted.end());

    for(int i=0; i<n; i++) std::cout << sorted[i] << '\n';

    return 0;
}