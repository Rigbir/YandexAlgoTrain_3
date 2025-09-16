//
// Created by Marat on 16.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> v[i][j];
        }
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(m));
    dp[0][0] = v[0][0];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + v[i][0];
    }
    for (int j = 1; j < m; ++j) {
        dp[0][j] = dp[0][j - 1] + v[0][j];
    }

    for (size_t i = 1; i < v.size(); ++i) {
        for (size_t j = 1; j < v[i].size(); ++j) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + v[i][j];
        }
    }

    std::cout << dp[n - 1][m - 1] << '\n';
}