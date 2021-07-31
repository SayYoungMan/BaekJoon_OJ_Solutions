#include <iostream>

// Assuming memo of visited is not required

int ans = 0;
int board[15];

bool isValid(int row) {
    for (int i=0; i < row; i++) {
        // If placed in the same column or same diagonal
        if ((board[i] == board[row]) || (row - i == abs(board[row] - board[i]))) {
            return false;
        }
    }

    return true;
}

void backTrack(int n, int row) {
    // Answer if satisfied
    if (row == n) {
        ans++; 
        return;
    }

    for (int i=0; i < n; i++) {
        // Place the queen on the current row
        board[row] = i;

        // Continue to next row if valid
        if (isValid(row)) backTrack(n, row + 1);
    }

    return;
}

int main() {
    int n;
    std::cin >> n;

    backTrack(n, 0);

    std::cout << ans;

    return 0;
}