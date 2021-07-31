#include <iostream>
#include <deque>
#include <limits>
#include <algorithm>

int max = std::numeric_limits<int>::min();
int min = std::numeric_limits<int>::max();

void backTrack(int n, std::deque<int> A, int add, int subst, int mult, int div) {
    if (n==1) {
        max = std::max(max, A[0]);
        min = std::min(min, A[0]);
        return;
    }

    if (add > 0) {
        std::deque<int> tmp = A;

        int a = tmp.front();
        tmp.pop_front();
        int b = tmp.front();
        tmp.pop_front();

        tmp.push_front(a+b);

        backTrack(n-1, tmp, add-1, subst, mult, div);
    }

    if (subst > 0) {
        std::deque<int> tmp = A;

        int a = tmp.front();
        tmp.pop_front();
        int b = tmp.front();
        tmp.pop_front();

        tmp.push_front(a-b);

        backTrack(n-1, tmp, add, subst-1, mult, div);
    }

    if (mult > 0) {
        std::deque<int> tmp = A;

        int a = tmp.front();
        tmp.pop_front();
        int b = tmp.front();
        tmp.pop_front();

        tmp.push_front(a*b);

        backTrack(n-1, tmp, add, subst, mult-1, div);
    }

    if (div > 0) {
        std::deque<int> tmp = A;

        int a = tmp.front();
        tmp.pop_front();
        int b = tmp.front();
        tmp.pop_front();

        tmp.push_front(a/b);

        backTrack(n-1, tmp, add, subst, mult, div-1);
    }

    return;
}

int main() {
    int n, add, subst, mult, div;
    std::deque<int> A;

    std::cin >> n;
    for (int i=0; i<n; i++) {
        int num;
        std::cin >> num;
        A.push_back(num);
    }

    std::cin >> add >> subst >> mult >> div;

    backTrack(n, A, add, subst, mult, div);

    std::cout << max << '\n';
    std::cout << min << '\n';

    return 0;
}