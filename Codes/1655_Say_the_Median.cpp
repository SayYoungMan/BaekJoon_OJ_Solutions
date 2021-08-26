#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, num, med = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int> > upper;
    std::priority_queue<int> lower;

    upper.push(10001);
    lower.push(-10001);

    std::cin >> n;

    for (int i=0; i < n; i++)
    {
        std::cin >> num;

        // 1. In the case where there is more upper than lower
        if (upper.size() > lower.size())
        {
            int tmp = upper.top();

            // If new num is greater than the smallest in upper than pop this and add to lower while adding the number to upper
            if (num > tmp)
            {
                upper.pop();
                upper.push(num);
                lower.push(tmp);
            }
            // If new num is less than or equal, then just push the number to the lower
            else
            {
                lower.push(num);
            }
        }

        // 2. In the case where there is more lower than upper
        else if (lower.size() > upper.size())
        {
            int tmp = lower.top();

            // If new num smaller than biggest in lower, pop this and add
            if (num < tmp)
            {
                lower.pop();
                lower.push(num);
                upper.push(tmp);
            }

            // Else, just add to upper
            else
            {
                upper.push(num);
            }
        }

        // 3. In the case where the number of elements equal in lower and upper
        else
        {
            // If num smaller than or equal to the biggest in lower just push to lower
            if (num <= lower.top())
                lower.push(num);
            
            // If num in between the middle two, also push to lower
            else if (num > lower.top() && num < upper.top())
                lower.push(num);

            // If num greater than or equal to smallest of upper, move the smallest of upper to lower and push number to upper
            else
            {
                int tmp = upper.top();
                upper.pop();
                upper.push(num);
                lower.push(tmp);
            }
        }

        // Print the top of lower
        std::cout << lower.top() << '\n';
    }

    return 0;
}