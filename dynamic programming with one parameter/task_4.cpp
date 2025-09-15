//
// Created by Marat on 13.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> v(n, std::vector<int>(3));
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    const int INF = 1e9;
    std::vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (size_t i = 1; i <= n; ++i) {
        dp[i] = std::min(dp[i], dp[i - 1] + v[i - 1][0]);

        if (i >= 2) {
            dp[i] = std::min(dp[i], dp[i - 2] + v[i - 2][1]);
        }

        if (i >= 3) {
            dp[i] = std::min(dp[i], dp[i - 3] + v[i - 3][2]);
        }
    }

    std::cout << dp[n] << '\n';
}