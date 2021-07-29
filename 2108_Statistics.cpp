#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, num, sum = 0, min = 4001, max = -4001;
    std::cin >> n;
    std::vector<int> nums(8005, 0);

    for (int i=0; i < n; i++) {
        std::cin >> num;

        sum += num;
        min = std::min(min, num);
        max = std::max(max, num);

        nums[num+4000]++;
    }

    int count = 0, mid = n/2, median, mode = 0;
    double avg;

    // 1. Calculate arithmetic avg
    avg = std::round( (double)sum / (double)n );
    std::cout << avg << '\n';

    // 2. Calculate median
    for (int i=0; i <= 8000; i++) {
        count += nums[i];
        if (count > mid) {
            std::cout << i - 4000 << '\n';
            break;
        }
    }

    // 3. Calculate mode
    int freq = 0;
    std::vector<int> mostFreq;

    // Find most frequent
    for (int i=0; i <= 8000; i++) {
        freq = std::max(freq, nums[i]);
    }

    // Put all of most frequents
    for (int i=0; i <= 8000; i++) {
        if (nums[i] == freq) mostFreq.push_back(i - 4000);
    }

    // Print mode
    if (mostFreq.size() > 1) std::cout << mostFreq[1] << '\n';
    else std::cout << mostFreq[0] << '\n';

    // 4. Calculate range
    std::cout << max - min << '\n';

    return 0;

}