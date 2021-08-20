#include <iostream>
#include <vector>

std::vector< std::vector<int> > paper;
int mone = 0;
int zero = 0;
int one = 0;

bool isZero(int row, int col, int n) {
    for (int i=row; i < row+n; i++) {
        for (int j=col; j < col+n; j++) {
            if (paper[i][j] != 0) return false;
        }
    }
    return true;
}

bool isOne(int row, int col, int n) {
    for (int i=row; i < row+n; i++) {
        for (int j=col; j < col+n; j++) {
            if (paper[i][j] != 1) return false;
        }
    }
    return true;
}

bool isMone(int row, int col, int n) {
    for (int i=row; i < row+n; i++) {
        for (int j=col; j < col+n; j++) {
            if (paper[i][j] != -1) return false;
        }
    }
    return true;
}

void dac(int row, int col, int n) {
    // std::cout << "row: " << row << " col: " << col << " n: " << n << '\n';

    if (isZero(row, col, n)) {
        zero++;
        return;
    }
    else if (isOne(row, col, n)) {
        one++;
        return;
    }
    else if (isMone(row, col, n)) {
        mone++;
        return;
    }
    else {
        dac(row, col, n/3);
        dac(row, col + n/3, n/3);
        dac(row, col + 2 * n/3, n/3);
        dac(row + n/3, col, n/3);
        dac(row + n/3, col + n/3, n/3);
        dac(row + n/3, col + 2 * n/3, n/3);
        dac(row + 2 * n/3, col, n/3);
        dac(row + 2 * n/3, col + n/3, n/3);
        dac(row + 2 * n/3, col + 2 * n/3, n/3);
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

        paper.push_back(row);
    }

    dac(0, 0, n);

    std::cout << mone << '\n';
    std::cout << zero << '\n';
    std::cout << one << '\n';

    return 0;
}