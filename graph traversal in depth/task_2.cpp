//
// Created by Marat on 17.09.25.
//

#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& graph,
         std::vector<bool>& visited,
         const int v,
         std::vector<int>& comp) {

    visited[v] = true;
    comp.push_back(v);

    for (const int to : graph[v]) {
        if (!visited[to]) {
            dfs(graph, visited, to, comp);
        }
    }
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

    std::vector<int> comp(n + 1, 0);
    std::vector<bool> visited(n + 1, false);
    std::vector<std::vector<int>> allComponents;

    for (int v = 1; v <= n; ++v) {
        if (!visited[v]) {
            comp.clear();
            dfs(graph, visited, v, comp);
            allComponents.push_back(comp);
        }
    }

    std::cout << allComponents.size() << '\n';
    for (auto& c : allComponents) {
        std::cout << c.size() << '\n';
        for (int i : c) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}