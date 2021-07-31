#include <iostream>

int main() {
    int maxVal = 0, maxIdx, num, c = 0;

    while(std::cin >> num) {
        c++;
        if (num > maxVal) {
            maxVal = num;
            maxIdx = c;
        }
    }

    std::cout << maxVal << '\n' << maxIdx;

    return 0;
}