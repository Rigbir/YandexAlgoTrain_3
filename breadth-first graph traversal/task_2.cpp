//
// Created by Marat on 18.09.25.
//

#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            std::cin >> x;
            if (x == 1) {
                graph[i].push_back(j);
            }
        }
    }

    std::vector<int> dist(n + 1, -1);
    std::vector<int> parent(n + 1, -1);
    std::queue<int> q;

    int start, end;
    std::cin >> start >> end;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        const int v = q.front();
        q.pop();

        for (const int to : graph[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                parent[to] = v;
                q.push(to);
            }
        }
    }

    if (dist[end] == -1) {
        std::cout << -1;
    } else {
        if (dist[end] == 0) {
            std::cout << dist[end] << '\n';
        } else {
            std::cout << dist[end] << '\n';

            std::vector<int> path;
            for (int v = end; v != -1; v = parent[v]) {
                path.push_back(v);
            }

            for (auto it = path.rbegin(); it != path.rend(); ++it) {
                std::cout << *it << ' ';
            }
        }
    }
}