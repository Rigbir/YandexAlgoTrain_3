//
// Created by Marat on 18.09.25.
//

#include <iostream>
#include <vector>
#include <queue>

int main() {
    int N, M, S, T, Q;
    std::cin >> N >> M >> S >> T >> Q;

    std::vector<std::pair<int, int>> graph(Q);
    for (int i = 0; i < Q; ++i) {
        std::cin >> graph[i].first >> graph[i].second;
    }

    std::vector<std::pair<int, int>> move = {
        {1, 2}, {-1, 2}, {-1, -2}, {1, -2},
        {2, 1}, {-2, 1}, {-2, -1}, {2, -1}
    };

    std::vector<std::vector<int>> dist(N + 1, std::vector<int>(M + 1, -1));
    std::queue<std::pair<int, int>> q;

    dist[S][T] = 0;
    q.push({S, T});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 8; ++k) {
            int xn = x + move[k].first;
            int yn = y + move[k].second;
            if (xn >= 1 && xn <= N && yn >= 1 && yn <= M && dist[xn][yn] == -1) {
                dist[xn][yn] = dist[x][y] + 1;
                q.push({xn, yn});
            }
        }
    }

    int ans = 0;
    for (auto [x, y] : graph) {
        if (dist[x][y] == -1) {
            std::cout << -1;
            return 0;
        }
        ans += dist[x][y];
    }

    std::cout << ans;
}