#include <iostream>

int revNum(int num) {
    int res = 0;

    res += (num % 10) * 100;
    num /= 10;
    res += (num % 10) * 10;
    num /= 10;
    res += num;

    return res;
}

int main() {
    int a, b;

    std::cin >> a >> b;

    a = revNum(a);
    b = revNum(b);

    if (a > b) {
        std::cout << a << std::endl;
    } else {
        std::cout << b << std::endl;
    }

    return 0;
}