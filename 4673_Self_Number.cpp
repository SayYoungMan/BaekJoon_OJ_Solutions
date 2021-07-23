#include <iostream>

int d(int num) {
    int sum = num;

    while (num > 0) {
        sum += (num % 10);
        num /= 10;
    }

    return sum;
}

int main() {
    bool a [10000];
    int tmp;

    for (int i=0; i<10000; i++) {
        a[i] = true;
    }

    for (int i=0; i<10000; i++) {
        tmp = d(i);
        if (tmp < 10000) {
            a[tmp] = false;
        }
    }

    for (int i=0; i<10000; i++) {
        if (a[i] == true) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}