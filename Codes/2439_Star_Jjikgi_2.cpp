#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::string starLine;

    std::cin >> n;

    for (int i=1; i <= n; i++) {
        starLine = "";

        for (int star=1; star <= i; star++) {
            starLine += "*";
        }
        std::cout << std::setw(n) << starLine << "\n";
    }

    return 0;
}