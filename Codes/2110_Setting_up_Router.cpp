#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

std::vector<int> homes;
int n, c;

bool isPossible(int d)
{
    int i = 0;
    int j = 1;
    int count = 1;

    while (j < n)
    {
        if (homes[j] - homes[i] >= d)
        {
            count++;
            i = j;
        }
        j++;
        // std::cout << "i: " << i << " j: " << j << " count: " << count << '\n';
    }

    if (count >= c) return true;
    else return false;
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> n >> c;

    int num;

    for (int i=0; i < n; i++)
    {
        std::cin >> num;
        homes.push_back(num);
    }

    std::sort(homes.begin(), homes.end());

    int h = homes.back() - homes.front();
    int l = 1;
    int m;

    while (l <= h)
    {
        m = (h + l) / 2;

        // std::cout << "h: " << h << " l: " << l << " m: " << m << '\n';

        if (isPossible(m) && !isPossible(m+1))
        {
            std::cout << m << '\n';
            return 0;  
        }

        else if (isPossible(m)) l = m + 1;
        else h = m - 1;
    }
}