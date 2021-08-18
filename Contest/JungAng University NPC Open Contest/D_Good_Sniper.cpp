#include <iostream>
#include <cmath>

int main() 
{
    long long t, x1, y1, r1, x2, y2, r2;
    double dist;

    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    dist = std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    
    // For the case where the circles have the same centre
    if (x1 == x2 && y1 == y2) 
    {
        std::cout << "YES";
    }

    // For the case where the one circle lies within the other
    else if (r1 >= dist + (double)r2 || r2 >= dist + (double)r1) 
    {
        std::cout << "YES";
    }

    // For the case where circles lie outside
    else 
    {
        if (dist > (double)(r1 + r2)) std::cout << "NO" << '\n';
        else if (dist == (double)(r1 + r2)) std::cout << "NO" << '\n';
        else std::cout << "YES" << '\n';
    }


    return 0;
}