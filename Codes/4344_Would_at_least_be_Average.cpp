#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int c, n, grade;
    float avg;

    std::cin >> c;

    for (int i=0; i<c; i++) {
        std::cin >> n;
        std::vector<int> grades;
        int ans = 0;

        for (int j=0; j<n; j++) {
            std::cin >> grade;
            grades.push_back(grade);
        }

        int sum = std::accumulate(grades.begin(), grades.end(), 0);
        avg = (float)sum / (float)n;

        for (int &grade : grades) {
            if (grade > avg) {
                ans += 1;
            }
        }

        printf("%.3f%\n", ((float)ans / (float)n) * 100);
    }

    return 0;
}