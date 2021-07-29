#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    long int x;
    std::vector<long int> xCoords;
    std::vector<long int> unique_xCoords;
    std::unordered_map<long int, int> xCoordsMap;

    std::cin >> n;

    // Add to original coord vector
    for (int i=0; i < n; i++) {
        std::cin >> x;
        xCoords.push_back(x);
    }

    // Remove duplicates and add to unique coord vector
    std::unordered_set<long int> s;
    for (auto &i: xCoords) s.insert(i);
    unique_xCoords.assign(s.begin(), s.end());

    // Sort the unique coord vector
    std::sort(unique_xCoords.begin(), unique_xCoords.end());

    // Assign each coord value to index to give its relative position
    int l = unique_xCoords.size();
    for (int i=0; i < l; i++) {
        xCoordsMap.insert({unique_xCoords[i], i});
    }

    // Print out the relative value of original coordinates
    for (auto &i : xCoords) std::cout << xCoordsMap.at(i) << ' ';

    return 0;
}