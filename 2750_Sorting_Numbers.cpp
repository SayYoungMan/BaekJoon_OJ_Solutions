#include <iostream>
#include <vector>

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
    
    int i=1;
    while(i < n) {
        int j = i;
        while (j > 0 && sorted[j-1] > sorted[j]) {
            std::swap(sorted[j], sorted[j-1]);
            j--;
        }
        i++;
    }

    for(int i=0; i<n; i++) std::cout << sorted[i] << '\n';

    return 0;
}