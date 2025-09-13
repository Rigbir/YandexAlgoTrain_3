//
// Created by Marat on 13.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        int ways = 0;
        for (int step = 1; step <= k; ++step) {
            if (i - step >= 0) {
                ways += dp[i - step];
            }
        }
        dp[i] = ways;
    }

    std::cout << dp[n - 1];
}
