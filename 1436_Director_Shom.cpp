#include <iostream>

bool is666(int num) {
    int consec = 0;

    while (num > 0) {
        if (num % 10 == 6) consec++;
        else consec = 0;

        if (consec == 3) return true;

        num /= 10;
    }

    return false;
}

int main() {
    int n, occ = 0, num = 666;
    std::cin >> n;

    while (true) {
        if (is666(num)) occ += 1;
        if (occ == n) {
            std::cout << num;
            break;
        }
        num++;
    }

    return 0;
}