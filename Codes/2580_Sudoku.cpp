#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

#define N 9

void printBoard(std::vector<std::vector<int>> board) {
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return;
}

bool isValid(std::vector<std::vector<int>> board) {
    // Check the rows
    for (int i=0; i < N; i++) {
        std::unordered_set<int> counter;
        for (int j=0; j < N; j++) {
            int num = board[i][j];
            if (num == 0) continue;
            else if (counter.count(num)) return false;
            else counter.insert(num);
        }
    }
    
    // Check the columns
    for (int j=0; j < N; j++) {
        std::unordered_set<int> counter;
        for (int i=0; i < N; i++) {
            int num = board[i][j];
            if (num == 0) continue;
            else if (counter.count(num)) return false;
            else counter.insert(num);
        }
    }

    // Check each boxes
    for (int top=0; top < N; top += 3) {
        for (int left=0; left < N; left += 3) {
            std::unordered_set<int> counter;
            for (int i=0; i < N/3; i++) {
                for (int j=0; j < N/3; j++) {
                    int num = board[top+i][left+j];
                    if (num == 0) continue;
                    else if (counter.count(num)) return false;
                    else counter.insert(num);
                }
            }
        }
    }

    return true;
}

void backTrack(std::vector<std::vector<int>> board, int zeros, std::set<std::pair<int, int>> zeroLoc) {
    // Check if valid
    if (!isValid(board)) return;

    // Check if done
    if (zeros == 0) {
        printBoard(board);
        exit(0);
    }

    for(const auto &pair: zeroLoc) {
        for (int i=1; i <= N; i++) {
            // Declare temporary variables
            std::vector<std::vector<int>> tmp = board;
            std::set<std::pair<int, int>> tmpSet = zeroLoc;
            
            // Try with new arbitrary values
            tmpSet.erase(pair);
            tmp[pair.first][pair.second] = i;
            backTrack(tmp, zeros-1, tmpSet);
        }
    }

    return;
}

int main() {
    std::vector<std::vector<int>> board(N, std::vector<int> (N));
    int n, zeros = 0;
    std::set<std::pair<int, int>> zeroLoc;

    // Get input of the board
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            std::cin >> n;
            board[i][j] = n;
            if (n == 0) {
                zeros++;
                zeroLoc.insert(std::make_pair(i, j));
            }
        }
    }

    backTrack(board, zeros, zeroLoc);

    return 0;
}