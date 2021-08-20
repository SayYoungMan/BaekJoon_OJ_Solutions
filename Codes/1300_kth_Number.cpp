#include <iostream>
#include <vector>
#include <algorithm>

int n, k;

bool isMore(int x)
{
    int count = 0;
    for (int row = 1; row <= n; row++)
    {
        count += x/row;
    }
    if (count >= k) return true;
    else return false;
}

int main()
{
    std::cin >> n >> k;

    int h = k;

    while
}