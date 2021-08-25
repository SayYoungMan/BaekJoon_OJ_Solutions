#include <iostream>
#include <vector>
#include <algorithm>

int n, k;

bool more_than(int x)
{
    int rv = 0;

    for (int i=1; i <= n; i++)
        rv += std::min(x/i, n);

    if (rv >= k) return true;
    else return false;
}

int main()
{
    std::cin >> n >> k;

    int h = k;
    int l = 1;
    int m;

    while (l <= h)
    {
        m = (h + l) / 2;

        if (more_than(m) && !more_than(m-1))
        {
            std::cout << m << '\n';
            return 0;
        }

        else if (more_than(m)) h = m - 1;
        else l = m + 1;
    }
}