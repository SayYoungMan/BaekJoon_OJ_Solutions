#include <iostream>
#include <bitset>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    long long n, t;
    std::cin >> t;

    for (int _=0; _ < t; _++)
    {
        std::cin >> n;
        n %= 28;

        if (n > 15) n = 30 - n;
        else if (n == 0) n = 2;

        std::string bin = std::bitset<4>(n).to_string();

        for (auto &c: bin)
        {
            if (c == '0') std::cout << 'V';
            else std::cout << "딸기";
        }

        std::cout << '\n';
    }

    return 0;
}
