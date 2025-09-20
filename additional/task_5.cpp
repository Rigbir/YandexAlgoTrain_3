//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <vector>

int maxCount(const std::vector<int>& v) {
    if (v.size() < 2) return 0;

    int minId = 0;
    int minVal = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] < minVal) {
            minVal = v[i];
            minId = i;
        }
    }

    std::vector<int> left(v.begin(), v.begin() + minId);
    std::vector<int> right(v.begin() + minId + 1, v.end());

    for (auto& x : left) {
        x -= minVal;
    }
    for (auto& x : right) {
        x -= minVal;
    }

    return (v.size() - 1) * minVal + maxCount(left) + maxCount(right);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> count(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> count[i];
    }

    std::cout << maxCount(count);
}