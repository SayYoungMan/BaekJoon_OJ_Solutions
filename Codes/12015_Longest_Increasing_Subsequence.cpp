#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> A;
int n, num;

int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0) // boundry case
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
 
    for (int i = 1; i < v.size(); i++) {
 
        // Do binary search for the element in
        // the range from begin to begin + length
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
 
        // If not present change the tail element to v[i]
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }

    return length;
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> n;
    for (int i=0; i < n; i++)
    {
        std::cin >> num;
        A.push_back(num);
    }

    int ans = LongestIncreasingSubsequenceLength(A);

    std::cout << ans << '\n';

    return 0;
}