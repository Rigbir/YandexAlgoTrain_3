//
// Created by Marat on 17.09.25.
//

#include <iostream>
#include <vector>
#include <algorithm>

void dfs(const std::vector<std::vector<int>>& graph,
         std::vector<bool>& visited,
         std::vector<int>& result,
         const int v) {

    visited[v] = true;
    result.push_back(v);
    for (const int to : graph[v]) {
        if (!visited[to]) {
            visited[to] = true;
            dfs(graph, visited, result, to);
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

    std::vector<bool> visited(n + 1, false);
    std::vector<int> result;

    dfs(graph, visited, result, 1);

    std::ranges::sort(result);

    std::cout << result.size() << "\n";
    for (int x : result) {
        std::cout << x << " ";
    }
}