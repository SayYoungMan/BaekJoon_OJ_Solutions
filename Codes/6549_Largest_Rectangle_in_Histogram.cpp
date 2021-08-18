#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>

int main() 
{
    int h;
    std::string line;

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while (true) 
    {
        std::stack< std::pair<int, int> > st;
        st.push(std::make_pair(-1, -1));
        long long max_area = 0;

        std::getline(std::cin, line);
        if (line == "0") break;

        // std::cout << line << '\n';

        std::istringstream iss(line);

        int i = 0;

        iss >> h;

        while(iss >> h)
        {
            while (st.top().second != -1 && st.top().second >= h) 
            {
                std::pair<int, int> top = st.top();
                st.pop();
                long long cur_height = top.second;
                long long cur_width = i - st.top().first - 1;
                max_area = std::max(max_area, cur_height * cur_width);
                // std::cout << "Max Area for h " << h << " and i " << i << " is " << max_area << '\n';
            }
            st.push(std::make_pair(i++, h));
        }

        while (st.top().second != -1)
        {
            std::pair<int, int> top = st.top();
            st.pop();
            long long cur_height = top.second;
            long long cur_width = i - st.top().first - 1;
            max_area = std::max(max_area, cur_height * cur_width);
            // std::cout << max_area << ' ' << cur_height * cur_width << '\n';
            // std::cout << "Max Area for h " << cur_height << " and w " << cur_width << " is " << max_area << '\n';
        }

        std::cout << max_area << '\n';
    }

    return 0;
}