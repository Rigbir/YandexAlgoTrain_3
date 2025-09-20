//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <vector>
#include <climits>

int main() {
    int k;
    std::cin >> k;

    std::vector<std::pair<int, int>> v(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> v[i].first >> v[i].second;
    }

    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first < minX) {
            minX = v[i].first;
        }
        if (v[i].first > maxX) {
            maxX = v[i].first;
        }
        if (v[i].second < minY) {
            minY = v[i].second;
        }
        if (v[i].second > maxY) {
            maxY = v[i].second;
        }
    }

    std::cout << minX << ' ' << minY << ' ' << maxX << ' ' << maxY;
}