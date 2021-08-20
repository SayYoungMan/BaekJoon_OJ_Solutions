#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int t;
    std::cin >> t;

    for (int c = 0; c < t; c++) {
        int n;
        std::cin >> n;

        std::vector<std::string> type_vec;
        std::vector<int> type_count;

        for (int cl = 0; cl < n; cl++) {
            std::string name, type;
            std::cin >> name >> type;

            auto it = std::find(type_vec.begin(), type_vec.end(), type);

            if (it != type_vec.end()) {
                int idx = it - type_vec.begin();
                type_count[idx]++;
            }
            else {
                type_vec.push_back(type);
                type_count.push_back(1);
            }
        }

        int ans = 1;
        for (int i = 0; i < type_count.size(); i++) {
            ans *= (type_count[i] + 1);
        }

        // for (auto &i: type_count) std::cout << i << " ";
        // std::cout << '\n';

        // int types = type_count.size();
        // int ans = 0;
        // for (int i=1; i <= types; i++) {
        //     std::string bitmask(i, 1);
        //     bitmask.resize(types, 0);

        //     do {
        //         std::vector<int> selected;
        //         for (int j = 0; j < types; j++)
        //         {
        //             if (bitmask[j]) selected.push_back(j);
        //         }
        //         int tmp = 1;
        //         for (auto &sel: selected) {
        //             tmp *= type_count[sel];
        //             // std::cout << "i: " << i << " sel: " << sel << " count: " << type_count[sel] << '\n';
        //         }
        //         // std::cout << "i: " << i << " tmp: " << tmp << '\n';
        //         ans += tmp; 
        //     } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
        // }

        std::cout << ans - 1 << '\n';
    }

    return 0;
}