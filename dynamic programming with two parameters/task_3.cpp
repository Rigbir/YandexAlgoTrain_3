//
// Created by Marat on 16.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> dp(n, std::vector<int>(m));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 1 && j > 0) {
                dp[i][j] += dp[i - 2][j - 1];
            }
            if (i > 0 && j > 1) {
                dp[i][j] += dp[i - 1][j - 2];
            }
        }
    }

    std::cout << dp[n - 1][m - 1];
}