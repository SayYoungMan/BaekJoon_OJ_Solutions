#include <iostream>

int main() {
    int org, attempt = 0;

    std::cin >> org;
    int num = org;

    if (num < 10 && num > 0) {
        num *= 11;
        attempt += 1;
    }

    while (true) {
        int tens = num / 10;
        int ones = num % 10;

        int sum = tens + ones;

        num = ones*10 + (sum % 10);

        attempt += 1;

        if (org == num) {
            break;
        }
    }

    std::cout << attempt;

    return 0;
}