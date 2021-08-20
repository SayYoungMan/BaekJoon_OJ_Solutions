#include <iostream>
#include <vector>

std::vector< std::vector<int> > input;
int white = 0;
int blue = 0;

bool isZero(int row, int col, int n) {
    for (int i=row; i < row+n; i++) {
        for (int j=col; j < col+n; j++) {
            if (input[i][j] == 1) return false;
        }
    }
    return true;
}

bool isOne(int row, int col, int n) {
    for (int i=row; i < row+n; i++) {
        for (int j=col; j < col+n; j++) {
            if (input[i][j] == 0) return false;
        }
    }
    return true;
}

void dac(int row, int col, int n) {
    // std::cout << "row: " << row << " col: " << col << " n: " << n << '\n';

    if (isZero(row, col, n)) {
        std::cout<< 0;
        return;
    }
    else if (isOne(row, col, n)) {
        std::cout<< 1;
        return;
    }
    else {
        std::cout << '(';
        dac(row, col, n/2);
        dac(row, col + n/2, n/2);
        dac(row + n/2, col, n/2);
        dac(row + n/2, col + n/2, n/2);
        std::cout << ')';
        return;
    }
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n;
    char num;

    std::cin >> n;

    for (int i=0; i < n; i++) {
        std::vector<int> row;

        for (int j=0; j < n; j++) {
            std::cin >> num;
            row.push_back((int) num - 48);
        }

        input.push_back(row);
    }

    dac(0, 0, n);

    return 0;
}