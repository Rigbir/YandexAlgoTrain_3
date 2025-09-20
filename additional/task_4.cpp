//
// Created by Marat on 19.09.25.
//

#include <iostream>

int main() {
    int n, k, p, rl;
    std::cin >> n >> k >> p >> rl;

    int petyaPos = (rl == 1 ? p * 2 - 1: p * 2);
    int petyaVariant = (petyaPos - 1) % k + 1;

    int bestPos = -1;
    int bestDist = 1e9;

    for (int pos = petyaVariant; pos <= n; pos += k) {
        if (pos == petyaPos) continue;
        int dist = std::abs((pos + 1) / 2 - (petyaPos + 1) / 2);

        if (dist < bestDist || (dist == bestDist && pos > petyaPos)) {
            bestDist = dist;
            bestPos = pos;
        }
    }

    if (bestPos == -1) {
        std::cout << -1;
    } else {
        int pos = (bestPos + 1) / 2;
        int var = (bestPos % 2 == 1 ? 1 : 2);
        std::cout << pos << ' ' << var;
    }
}