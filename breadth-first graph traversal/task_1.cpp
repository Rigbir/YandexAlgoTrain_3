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

    int start, end;
    std::cin >> start >> end;

    std::vector<int> dist(n + 1, -1);
    std::queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        const int v = q.front();
        q.pop();

        if (v == end) break;

        for (const int to : graph[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    if (dist[end] == -1) {
        std::cout << -1;
    } else {
        std::cout << dist[end];
    }
}