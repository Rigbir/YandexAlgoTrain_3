//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> count(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> count[i];
    }

    long long cnt = 0;
    for (int i = 0; i + 1 < n; ++i) {
        cnt += std::min(count[i], count[i + 1]);
    }

    std::cout << cnt;
}