//
// Created by Marat on 18.09.25.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct Node {
    int z, x, y;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::string>> cave(n, std::vector<std::string>(n));

    int sz = 0, sx = 0, sy = 0;
    for (int z = 0; z < n; ++z) {
        std::string line;
        std::getline(std::cin, line);
        for (int x = 0; x < n; ++x) {
            std::cin >> cave[z][x];
            for (int y = 0; y < n; ++y) {
                if (cave[z][x][y] == 'S') {
                    sz = z; sx = x; sy = y;
                }
            }
        }
    }

    const Node start = {sz, sx, sy};

    std::vector<std::vector<std::vector<int>>> dist(
        n,
        std::vector<std::vector<int>>(
            n,
            std::vector<int>(n, -1)
        )
    );

    std::queue<Node> q;

    dist[start.z][start.x][start.y] = 0;
    q.push(start);

    const std::vector<int> dz = {0, 0, 0, 0, 1, -1};
    const std::vector<int> dx = {1, -1, 0, 0, 0, 0};
    const std::vector<int> dy = {0, 0, 1, -1, 0, 0};

    while (!q.empty()) {
        auto [z, x, y] = q.front();
        q.pop();

        if (z == 0) {
            std::cout << dist[z][x][y] << '\n';
            break;
        }

        for (int i = 0; i < 6; ++i) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nz >= 0 && nz < n &&
                nx >= 0 && nx < n &&
                ny >= 0 && ny < n && dist[nz][nx][ny] == -1) {

                if (cave[nz][nx][ny] == '.') {
                    dist[nz][nx][ny] = dist[z][x][y] + 1;
                    q.push({nz, nx, ny});
                }
            }
        }
    }
}