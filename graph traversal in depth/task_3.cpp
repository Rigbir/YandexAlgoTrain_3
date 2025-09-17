//
// Created by Marat on 17.09.25.
//

#include <iostream>
#include <vector>

enum class Color { white, gray, dark };

bool dfs(const std::vector<std::vector<int>>& graph,
         std::vector<Color>& visited,
         const int v,
         const Color c) {

    visited[v] = c;

    for (const int to : graph[v]) {
        if (visited[to] == Color::white) {
            if (!dfs(graph, visited, to, c == Color::gray ? Color::dark : Color::gray)) {
                return false;
            }
        }
        if (visited[to] == c) {
            return false;
        }
    }

    return true;
}

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

    std::vector<Color> visited(n + 1, Color::white);

    bool bipartite = true;
    for (int v = 1; v <= n; ++v) {
        if (visited[v] == Color::white) {
            if (!dfs(graph, visited, v, Color::gray)) {
                bipartite = false;
                break;
            }
        }
    }

    std::cout << (bipartite ? "YES" : "NO");
}