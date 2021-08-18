#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
#include <tuple>

typedef long long ll;

struct point
{
    ll x, y;
};

struct compareX
{
    inline bool operator() (const point& p1, const point& p2)
    {
        return (std::tie(p1.x, p1.y) < std::tie(p2.x, p2.y));
    }
};

struct compareY
{
    inline bool operator() (const point& p1, const point& p2)
    {
        return (std::tie(p1.y, p1.x) < std::tie(p2.y, p2.x));
    }
};

typedef std::vector<point> pv;

ll dist(point p1, point p2)
{
    return ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));
}

// Find the minimum distance within striped vector
ll closest_strip(pv &strip, ll d)
{
    std::sort(strip.begin(), strip.end(), compareY());

    int n = strip.size();
    ll min = LLONG_MAX;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n && (strip[j].y - strip[i].y) < min; j++)
            min = std::min(min, dist(strip[i], strip[j]));

    return min;
}

// Recursive function to find the pair of points with minimum distance
ll closest_util(pv &Px, pv &Py)
{
    int n = Px.size();

    // Base case
    if (n <= 3)
    {
        ll min = LLONG_MAX;
        for (int i=0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                min = std::min(min, dist(Px[i], Px[j]));
            }
        }

        return min;
    }

    int mid = n/2;
    ll midX = Px[mid].x;

    pv Pyl, Pyr, Pxl, Pxr;
    int li = 0;

    // Divide Px and Py into two halves
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= midX && li < mid)
        {
            Pyl.push_back(Py[i]);
            li++;
        }
        else Pyr.push_back(Py[i]);
    }
    for (int i = 0; i <= mid; i++) Pxl.push_back(Px[i]);
    for (int i = mid+1; i < n; i++) Pxr.push_back(Px[i]);

    // Find the smallest distance between the halves
    ll d = std::min(closest_util(Pxl, Pyl), closest_util(Pxr, Pyr));

    if (d == 0) return 0;

    // Take d as the upper bound of minimum distances
    // Consider points that are closer than d with respect to centre line
    
    pv strip;

    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midX) < d)
            strip.push_back(Py[i]);

    return std::min(d, closest_strip(strip, d));
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    ll n, x, y;

    std::cin >> n;

    pv Px(n);
    pv Py(n);

    point prev;
    prev.x = 10001;
    prev.y = 10001;

    for (int i=0; i < n; i++)
    {
        std::cin >> x >> y;
        point pt;
        pt.x = x;
        pt.y = y;
        Px[i] = pt;
        Py[i] = pt;

        if (pt.x == prev.x && pt.y == prev.y)
        {
            std::cout << 0 << '\n';
            return 0;
        }
        prev = pt;
    }

    std::sort(Px.begin(), Px.end(), compareX());
    std::sort(Py.begin(), Py.end(), compareY());

    std::cout << closest_util(Px, Py) << '\n';

    return 0;
}