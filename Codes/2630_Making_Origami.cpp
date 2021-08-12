#include <iostream>
#include <vector>

std::vector< std::vector<int> > origami;
int white = 0;
int blue = 0;

bool isWhite(int row, int col, int n) {
    for (int i=row; i < row+n; i++) {
        for (int j=col; j < col+n; j++) {
            if (origami[i][j] == 1) return false;
        }
    }
    return true;
}

bool isBlue(int row, int col, int n) {
    for (int i=row; i < row+n; i++) {
        for (int j=col; j < col+n; j++) {
            if (origami[i][j] == 0) return false;
        }
    }
    return true;
}

void dac(int row, int col, int n) {
    // std::cout << "row: " << row << " col: " << col << " n: " << n << '\n';

    if (isWhite(row, col, n)) {
        white++;
        return;
    }
    else if (isBlue(row, col, n)) {
        blue++;
        return;
    }
    else {
        dac(row, col, n/2);
        dac(row, col + n/2, n/2);
        dac(row + n/2, col, n/2);
        dac(row + n/2, col + n/2, n/2);
        return;
    }
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n, num;

    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::vector<int> row;

        for (int j=0; j < n; j++) {
            std::cin >> num;
            row.push_back(num);
        }

        origami.push_back(row);
    }

    dac(0, 0, n);

    std::cout << white << '\n';
    std::cout << blue << '\n';

    return 0;
}