//
// Created by Marat on 16.09.25.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> v[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 1e9));
    dp[0][0] = 0;

    for (int day = 1; day <= n; ++day) {
        for (int cupons = 0; cupons <= n; ++cupons) {
            if (cupons + 1 <= n) {
                dp[day][cupons] = std::min(dp[day][cupons], dp[day - 1][cupons + 1]);
            }

            if (v[day] > 100 && cupons > 0) {
                dp[day][cupons] = std::min(dp[day][cupons],
                                           dp[day - 1][cupons - 1] + v[day]);
            } else {
                dp[day][cupons] = std::min(dp[day][cupons],
                                        dp[day - 1][cupons] + v[day]);
            }
        }
    }

    int minCost = 1e9, remainingCoupons = 0;
    for (int c = 0; c <= n; c++) {
        if (dp[n][c] <= minCost) {
            minCost = dp[n][c];
            remainingCoupons = c;
        }
    }

    int coupons = remainingCoupons;
    int spentCoupons = 0;
    std::vector<int> couponDays;

    for (int day = n; day >= 1; --day) {
        if (coupons + 1 <= n &&
            dp[day][coupons] == dp[day - 1][coupons + 1]) {
            ++spentCoupons;
            couponDays.push_back(day);
            ++coupons;
            continue;
        }
        if (v[day] > 100 && coupons > 0 &&
            dp[day][coupons] == dp[day - 1][coupons - 1] + v[day]) {
            --coupons;
        }
    }
    std::ranges::reverse(couponDays);

    std::cout << minCost << "\n";
    std::cout << remainingCoupons << " " << spentCoupons << "\n";
    for (int d : couponDays) std::cout << d << "\n";
}