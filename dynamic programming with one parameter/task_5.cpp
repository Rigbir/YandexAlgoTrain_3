//
// Created by Marat on 13.09.25.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::ranges::sort(v);

    std::vector<int> dp(n);
    dp[0] = 0;
    dp[1] = v[1] - v[0];

    for (int i = 2; i < n; ++i) {
        if (i + 1 == n) {
            dp[i] = dp[i - 1] + v[i] - v[i - 1];
            continue;
        }

        dp[i] = std::min(dp[i - 1] + v[i] - v[i - 1], dp[i - 2] + v[i - 1] - v[i - 2]);
    }

    std::cout << dp[n - 1];
}