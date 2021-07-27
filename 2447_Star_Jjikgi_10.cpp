#include <iostream>
#include <vector>

std::vector<std::vector<int>> mat;

void insertStar(int n, int x, int y) {
    // printf("n:%i, x:%i, y:%i\n", n, x, y);

    if (n == 1) {
        mat[x][y] = 1;
        // printf("x:%i, y:%i\n", x, y);
        return;
    }

    for(int i=x; i<n+x; i+=(n/3)) insertStar(n/3, i, y);
    insertStar(n/3, x, y+n/3);
    insertStar(n/3, x+(2*n/3), y+n/3);

    for(int i=x; i<n+x; i+=(n/3)) insertStar(n/3, i, y+(2*n/3));

    return;
}

int main() {
    int n;
    std::cin >> n;

    for(int i=0; i<n; i++) mat.push_back(std::vector<int>(n, 0));

    insertStar(n, 0, 0);

    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            printf("%c", (mat[x][y] == 1) ? '*' : ' ');
        }
        std::cout << '\n';
    }

    return 0;
}