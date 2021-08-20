#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> trees;
int n, m;

bool isEnough(int h)
{
    long long r = 0;

    for (int i=0; i < n; i++)
    {
        if (trees[i] > h) r += (trees[i] - h);
        // std::cout << "m: " << m << " r: " << r << '\n';
        if (r >= m) return true;
    }

    return false;
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> n >> m;

    int num;

    for (int i=0; i < n; i++)
    {
        std::cin >> num;
        trees.push_back(num);
    }

    int h = *std::max_element(trees.begin(), trees.end()) - 1;
    int l = 0;

    while (l <= h)
    {
        int m = (h + l) / 2;

        // std::cout << "m: " << m << '\n';

        if (isEnough(m) && !isEnough(m+1))
        {
            std::cout << m << '\n';
            return 0;
        }

        else if (isEnough(m))
            l = m + 1;
        
        else
            h = m - 1;
    }

    return 0;
}