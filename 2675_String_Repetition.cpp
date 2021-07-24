#include <iostream>
#include <string>

int main() {
    int t, r;
    std::string s;

    std::cin >> t;
    for (int i=0; i<t; i++) {
        std::cin >> r >> s;

        std::string p = "";

        for (const char &c: s) {
            for (int j=0; j<r; j++) {
                p += c;
            }
        }

        std::cout << p << std::endl;
    }

    return 0;
}