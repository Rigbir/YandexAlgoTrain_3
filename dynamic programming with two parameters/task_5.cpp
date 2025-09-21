//
// Created by Marat on 16.09.25.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v1[i];
    }

    int m;
    std::cin >> m;

    std::vector<int> v2(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> v2[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    dp[0][0] = 0;

    for (int i = 1; i <= v1.size(); ++i) {
        for (int j = 1; j <= v2.size(); ++j) {
            if (v1[i - 1] == v2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                continue;
            }
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    std::vector<int> result;
    int i = v1.size();
    int j = v2.size();

    while (i > 0 || j > 0) {
        if (i > 0 && dp[i][j] == dp[i - 1][j]) {
            i -= 1;
        } else if (j > 0 && dp[i][j] == dp[i][j - 1]) {
            j -= 1;
        } else {
            result.push_back(v1[i - 1]);
            i -= 1;
            j -= 1;
        }
    }

    std::ranges::reverse(result);
    for (auto i : result) {
        std::cout << i << ' ';
    }
}