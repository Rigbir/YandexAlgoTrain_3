//
// Created by Marat on 17.09.25.
//

#include <iostream>
#include <vector>

enum class Color { white, gray, black };

bool dfs(const std::vector<std::vector<int>>& graph,
         std::vector<Color>& visited,
         std::vector<int>& result,
         const int v) {

    visited[v] = Color::gray;

    for (const int to : graph[v]) {
        if (visited[to] == Color::white) {
            if (dfs(graph, visited, result, to)) {
                return true;
            }
        } else if (visited[to] == Color::gray) {
            return true;
        }
    }

    visited[v] = Color::black;
    result.push_back(v);
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
    }

    std::vector<Color> visited(n + 1, Color::white);
    std::vector<int> result;

    bool cicleFound = false;
    for (int v = 1; v <= n; ++v) {
        if (visited[v] == Color::white) {
            if (dfs(graph, visited, result, v)) {
                cicleFound = true;
                break;
            }
        }
    }

    if (cicleFound) {
        std::cout << -1;
    } else {
        for (auto it = result.rbegin(); it != result.rend(); ++it) {
            std::cout << *it << ' ';
        }
    }
}
