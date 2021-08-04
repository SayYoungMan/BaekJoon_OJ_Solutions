#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define MAX_N 100

std::vector<int> A (MAX_N + 5, 0);
std::vector<int> B (MAX_N + 5, 0);

std::vector<int> cross (MAX_N + 5, 0);
std::unordered_map<int, std::vector<int>> cable_map;

bool isCross(int a1, int a2, int b1, int b2) {
    return (a1 > a2 && b1 < b2) || (a1 < a2 && b1 > b2);
}

void addToMap(int key, int val) {
    // If key not in map insert new key with vector with val
    if ( cable_map.find(key) == cable_map.end() ) {
        cable_map.insert({ key, {val} });
    }
    // Otherwise, push_back to the existing vector of key
    else {
        cable_map[key].push_back(val);
    }

    return;
}

int main() {
    int n, a, b, ans;
    std::cin >> n;

    // Get Input and process each cable location
    for (int i=0; i < n; i++) {
        std::cin >> a >> b;

        for (int j=0; j < i; j++) {

            // If cable i crosses with cable j
            if (isCross(a, A[j], b, B[j])) {
                // Record total number of cables crossing
                cross[i]++;
                cross[j]++;
                // Record the cables crossing each other
                addToMap(i, j);
                addToMap(j, i);
            }
        }

        A[i] = a;
        B[i] = b;
    }

    while (true) {
        int cross_max = 0, max_loc;
        // Find the cable that is most crossed and get its location
        for (int i=0; i<n; i++) {
            if (cross[i] > cross_max) {
                cross_max = cross[i];
                max_loc = i;
            }
        }

        // If no crossing break
        if (cross_max == 0) break;

        cross[max_loc] = 0;
        for (auto &i: cable_map[max_loc]) cross[i]--;
        cable_map.erase(max_loc);
        ans++;

        std::cout << "cross_max at " << max_loc <<  ": " << cross_max << '\n';
    }

    std::cout << ans;

    return 0;
}