#include <iostream>

int main() {
    int n, step=1, nu = 1, de=1;

    std::cin >> n;

    while (n != step) {

        // If at the top of matrix
        if (nu == 1) {
            // If odd top move right
            if (de % 2 == 1) {
                de += 1;
            } 
            // If even continue left down
            else {
                nu += 1;
                de -= 1;
            }
        }

        // If at the left most of matrix
        else if (de == 1) {
            // If even move down
            if (nu % 2 == 0) {
                nu += 1;
            }
            // If odd continue right up
            else {
                nu -= 1;
                de += 1;
            }
        }

        // If at even diagonal move up right
        else if ((nu + de) % 2 == 0) {
            nu -= 1;
            de += 1;
        }

        // If at odd diagonal move down left
        else {
            nu += 1;
            de -= 1;
        }

        step++;
    }

    printf("%i/%i", nu, de);

    return 0;
}