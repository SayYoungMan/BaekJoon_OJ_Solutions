#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, num;
    std::vector<int> heap;

    std::cin >> n;

    for (int i=0; i < n; i++)
    {
        std::cin >> num;

        if (num == 0)
        {
            if (heap.empty()) std::cout << 0 << '\n';

            else
            {
                std::cout << heap.front() << '\n';
                std::pop_heap(heap.begin(), heap.end());
                heap.pop_back();
            }
        }

        else
        {
            heap.push_back(num);
            std::push_heap(heap.begin(), heap.end());
        }
    }

    return 0;
}