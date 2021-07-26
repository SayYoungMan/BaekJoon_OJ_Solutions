#include <iostream>
#include <vector>

std::vector<bool> che(int n) {

    std::vector<bool> nums(n+1);

    std::fill(nums.begin(), nums.end(), true);
    nums[1] = false;

    for (int i=2; i*i <= n; i++) {
        if (nums[i] == true) {
            for (int j = i*i; j <= n; j+=i) nums[j] = false;
        }
    }

    return nums;
}

int main() {
    int t, n;

    std::cin >> t;
    for (int i=0; i < t; i++) {
        std::cin >> n;

        std::vector<bool> primes = che(n);
        // for (int j=0; j <= n; j++) printf("%d is: %s\n", j, primes[j] ? "True" : "False");

        for (int j=n/2; j > 0; j--) {
            // printf("For n %i: try %i and %i\n", n, j, n-j);
            if (primes[j] && primes[n-j]) {
                printf("%i %i\n", j, n-j);
                break;
            }
        }
    }

    return 0;
}