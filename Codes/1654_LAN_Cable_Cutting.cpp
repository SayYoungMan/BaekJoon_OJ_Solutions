#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

bool can_make(std::vector<ll> &wires, ll len, ll req)
{
    ll n = wires.size();
    ll x = 0;

    for (ll i=0; i < n; i++)
    {
        x += wires[i] / len;
        if (x >= req) return true;
    }

    return false;
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    ll k, n, num;
    std::cin >> k >> n;

    std::vector<ll> wires;

    for (ll i=0; i < k; i++)
    {
        std::cin >> num;
        wires.push_back(num);
    }

    ll h = *std::max_element(wires.begin(), wires.end());
    ll l = 1;

    if (n == 1) 
    {
        std::cout << h << '\n';
        return 0;
    }

    while (l <= h)
    {
        ll m = (h + l) / 2;
        // std::cout << "m: " << m << '\n'; 

        if (can_make(wires, m, n) && !can_make(wires, m+1, n))
        {
            std::cout << m << '\n';
            return 0;
        }

        else if (can_make(wires, m, n))
            l = m + 1;

        else
            h = m - 1;
    }
    
    std::cout << "not found" << '\n';
    return 0;
}