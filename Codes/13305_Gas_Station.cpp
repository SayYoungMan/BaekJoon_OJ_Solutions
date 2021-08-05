#include <iostream>
#include <vector>

int main() {
    long long int n, num;
    std::vector<long long int> distance;
    std::vector<long long int> price;

    std::cin >> n;
    for (int i=0; i < n-1; i++) {
        std::cin >> num;
        distance.push_back(num);
    }

    for (int i=0; i < n; i++) {
        std::cin >> num;
        price.push_back(num);
    }

    long long int ans = 0;
    int front = 0, back = 0;

    while (front < n-1) {
        if (price[back] <= price[front]) {
            long long int tmp = price[back] * distance[front];
            ans += tmp;
            front++;
        } else {
            back = front;
        }
    }

    std::cout << ans;

    return 0;

}