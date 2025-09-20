//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> count(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> count[i];
    }

    int minCount = 0;
    for (int i = 0; i + 1 < n; ++i) {
        minCount += std::min(count[i], count[i + 1]);
    }

    std::cout << minCount;
}