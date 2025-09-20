//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <vector>

void removeFromVector(std::vector<std::pair<int, int>>& v, int ind) {
    v[ind] = v.back();
    v.pop_back();
}

void removeFromSection(std::vector<std::pair<int, int>>& v, int start, int end) {
    for (int i = v.size() - 1; i >= 0; --i) {
        int s_start = v[i].first;
        int s_end = v[i].second;

        if (!(start > s_end || end < s_start)) {
            removeFromVector(v, i);
        }
    }
}

int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<std::pair<int, int>> section;
    for (int i = 0; i < n; ++i) {
        int start, end;
        std::cin >> start >> end;

        removeFromSection(section, start, end);
        section.push_back({start, end});
    }

    std::cout << section.size();
}
