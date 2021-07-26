#include <iostream>

int main() {
    int notes [8];
    bool ascend;

    std::cin >> notes[0];
    ascend = (notes[0] == 1) ? true : false;

    for (int i=1; i < 8; i++) {
        std::cin >> notes[i];
        if ((ascend && notes[i] < notes[i-1]) || (!ascend && notes[i] > notes[i-1])) {
            std::cout << "mixed";
            return 0;
        }
    }

    printf("%s", (ascend) ? "ascending" : "descending");

    return 0;

}