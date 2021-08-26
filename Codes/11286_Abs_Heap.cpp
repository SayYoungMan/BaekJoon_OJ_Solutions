#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

class absComparator
{
public:
    bool operator() (int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, num;
    std::priority_queue<int, std::vector<int>, absComparator> pq;

    std::cin >> n;

    for (int i=0; i < n; i++)
    {
        std::cin >> num;

        if (num == 0)
        {
            if(pq.empty())
                std::cout << 0 <<'\n';
            else
            {
                std::cout << pq.top() << '\n';
                pq.pop();
            }
        }

        else
        {
            pq.push(num);
        }
    }

    return 0;
}