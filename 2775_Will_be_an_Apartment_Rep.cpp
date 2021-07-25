#include <iostream>
#include <vector>

// 1 5 15 35 70
// 1 4 10 20 35
// 1 3 6  10 15
// 1 2 3  4  5

int main() {
    int t, k, n;
    std::cin >> t;

    for (int i=0; i<t; i++) {
        std::cin >> k >> n;

        std::vector<int> people(n);

        for (int j=0; j<n; j++) {
            people[j] = j+1;
        }

        int f = 1;

        while (f <= k) {
            int sum = 0;
            for (int j=1; j<n; j++) {
                people[j] = people[j] + people[j-1];
                // printf("people[%i] in floor %i is %i\n", j, f, people[j]);
            }
            f++;
        }

        std::cout << people[n-1] << std::endl; 
    }

    return 0;
}