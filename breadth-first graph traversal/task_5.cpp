//
// Created by Marat on 18.09.25.
//

#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> lines(m);
    for (int i = 0; i < m; ++i) {
        int p;
        std::cin >> p;
        lines[i].resize(p);
        for (int j = 0; j < p; ++j) {
            std::cin >> lines[i][j];
        }
    }

    std::vector<std::vector<int>> stationToLines(n + 1);
    for (int i = 0; i < m; ++i) {
        for (const auto st : lines[i]) {
            stationToLines[st].push_back(i);
        }
    }

    std::vector<std::vector<int>> graph(m);
    for (int st = 1; st <= n; ++st) {
        const auto& vec = stationToLines[st];
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = i + 1; j < vec.size(); ++j) {
                int l1 = vec[i], l2 = vec[j];
                graph[l1].push_back(l2);
                graph[l2].push_back(l1);
            }
        }
    }

    std::vector<int> dist(m + 1, -1);
    std::queue<int> q;

    int start, end;
    std::cin >> start >> end;

    if (start == end) {
        std::cout << 0 << '\n';
        return 0;
    }

    for (int line : stationToLines[start]) {
        dist[line] = 0;
        q.push(line);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int st : lines[v]) {
            if (st == end) {
                std::cout << dist[v] << '\n';
                return 0;
            }
        }

        for (const int to : graph[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    std::cout << -1 << '\n';
}