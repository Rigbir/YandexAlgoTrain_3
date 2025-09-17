//
// Created by Marat on 17.09.25.
//

#include <iostream>
#include <vector>

enum class Color { white, gray, black };

int start = -1, end = -1;

bool dfs(const std::vector<std::vector<int>>& graph,
         std::vector<Color>& visited,
         std::vector<int>& result,
         const int v,
         const int parent) {

    visited[v] = Color::gray;
    result[v] = parent;

    for (const int to : graph[v]) {
        if (to != parent && visited[to] == Color::gray) {
            start = to;
            end = v;
            return true;
        }

        if (visited[to] == Color::white) {
            result[to] = v;
            if (dfs(graph, visited, result, to, v)) {
                return true;
            }
        }
    }

    visited[v] = Color::black;
    return false;
}

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

    std::vector<Color> visited(n + 1, Color::white);
    std::vector<int> parent(n + 1, -1);

    bool cicleFound = false;
    for (int v = 1; v <= n; ++v) {
        if (visited[v] == Color::white) {
            if (dfs(graph, visited,parent, v, -1)) {
                cicleFound = true;
                break;
            }
        }
    }

    if (cicleFound) {
        std::cout << "YES\n";
        std::vector<int> output;
        output.push_back(start);
        for (int v = end; v != start; v = parent[v]) {
            output.push_back(v);
        }
        std::cout << output.size() << '\n';

        for (const auto i : output) {
            std::cout << i << ' ';
        }
    } else {
        std::cout << "NO\n";
    }
}
