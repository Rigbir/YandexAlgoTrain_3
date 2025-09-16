//
// Created by Marat on 16.09.25.
//

#include <iostream>
#include <vector>
#include <algorithm>

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

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + v[i][j];
        }
    }

    int i = n - 1, j = m - 1;
    std::string path;
    while (i > 0 || j > 0) {
        if (i > 0 && dp[i][j] == dp[i -1][j] + v[i][j]) {
            path.push_back('D');
            --i;
        } else {
            path.push_back('R');
            --j;
        }
    }
    std::ranges::reverse(path);

    std::cout << dp[n - 1][m - 1] << '\n';
    for (const auto c : path) {
        std::cout << c << ' ';
    }
}