//
// Created by Marat on 13.09.25.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1);
    std::vector<int> parent(n + 1);

    dp[1] = 0;
    parent[1] = -1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        parent[i] = i - 1;

        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            parent[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            parent[i] = i / 3;
        }
    }

    std::cout << dp[n] << '\n';

    std::vector<int> path;
    for (int x = n; x != -1; x = parent[x]) {
        path.push_back(x);
    }
    std::ranges::reverse(path);

    for (const auto p : path) {
        std::cout << p << ' ';
    }
}