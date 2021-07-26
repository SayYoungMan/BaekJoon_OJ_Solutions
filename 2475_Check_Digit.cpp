#include <iostream>

int main() {
    int num, sqsum = 0;

    for (int i=0; i < 5; i++) {
        std::cin >> num;
        sqsum += num * num;
    }

    std::cout << sqsum % 10;

    return 0;
}