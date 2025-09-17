//
// Created by Marat on 17.09.25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<bool> visited(n + 1, false);
    std::vector<int> result;
    std::queue<int> q;

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        result.push_back(v);
        for (int to : graph[v]) {
            if (!visited[to]) {
                visited[to] = true;
                q.push(to);
            }
        }
    }

    std::ranges::sort(result);

    std::cout << result.size() << "\n";
    for (int x : result) {
        std::cout << x << " ";
    }
}