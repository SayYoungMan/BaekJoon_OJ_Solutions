#include <iostream>
#include <cmath>

// ## Procedure
// 1. Move n-1 disks from the source to aux
// 2. Move largest disk from the source to target
// 3. Becomes a smaller sub-problem with aux becoming source and source becoming aux
// 4. Recurse until n = 0

void ToH(int n, int source, int target, int aux) {
    if (n == 0) return;

    ToH(n - 1, source, aux, target);

    printf("%i %i\n", source, target);

    ToH(n - 1, aux, target, source);

    return;
}

int main() {
    int n, moves;
    std::cin >> n;

    moves = std::pow(2, n) - 1;
    std::cout << moves << '\n';
    ToH(n, 1, 3, 2);

    return 0;
}