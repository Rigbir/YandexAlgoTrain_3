//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::cin.ignore();

    std::vector<std::vector<int> > matrix(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::vector<int>> prefSum(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefSum[i][j] = matrix[i][j]
                          + prefSum[i - 1][j]
                          + prefSum[i][j - 1]
                          - prefSum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int sum = prefSum[x2][y2]
                - prefSum[x1 - 1][y2]
                - prefSum[x2][y1 - 1]
                + prefSum[x1 - 1][y1 - 1];

        std::cout << sum << '\n';
    }
}
