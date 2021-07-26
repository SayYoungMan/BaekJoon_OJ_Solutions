#include <iostream>
#include <algorithm>

int main() {
    int sorted [3];

    while (true) {
        std::cin >> sorted[0] >> sorted[1] >> sorted[2];

        if (sorted[0] == 0 && sorted[1] == 0 && sorted[2] == 0) break;

        std::sort(sorted, sorted+3);

        printf("%s\n", (sorted[2]*sorted[2] == sorted[0]*sorted[0] + sorted[1]*sorted[1]) ? "right" : "wrong");
    }

    return 0;
}