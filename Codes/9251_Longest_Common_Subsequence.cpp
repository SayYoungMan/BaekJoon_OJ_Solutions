#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX_LEN 1000

std::vector<char> A (MAX_LEN + 5, 0);
std::vector<char> B (MAX_LEN + 5, 0);
std::vector<std::vector<int>> lcs (MAX_LEN + 5, std::vector<int>(MAX_LEN + 5, 0));

int main() {
    std::string str;

    std::cin >> str;
    int A_len = str.length();
    for (int i=1; i <= A_len; i++) A[i] = str[i-1];

    std::cin >> str;
    int B_len = str.length();
    for (int i=1; i <= B_len; i++) B[i] = str[i-1];

    for (int i=1; i <= A_len; i++) {
        for (int j=1; j <= B_len; j++) {
            if (A[i] == B[j]) lcs[i][j] = lcs[i-1][j-1] + 1;   
            else lcs[i][j] = std::max(lcs[i][j-1], lcs[i-1][j]);
        }
    }

    std::cout << lcs[A_len][B_len];

    return 0;
}