#include <iostream>
#include <numeric>

int main() {
    int x, y;
    int xList [2] = { 0 };
    int yList [2] = { 0 };

    for (int i=0; i < 3; i++) {
        std::cin >> x >> y;

        for (int i=0; i < 2; i++) {
            if (xList[i] == x) {
                xList[i] = 0;
                break;
            } else if (xList[i] == 0) {
                xList[i] = x;
                break;
            }
        }

        for (int i=0; i < 2; i++) {
            if (yList[i] == y) {
                yList[i] = 0;
                break;
            } else if (yList[i] == 0) {
                yList[i] = y;
                break;
            }
        }

    }

    printf("%i %i", std::accumulate(xList, xList+2, 0), std::accumulate(yList, yList+2, 0));

    return 0;
}
