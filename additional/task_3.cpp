//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int lBinSearch(int l, int r, int x, const std::vector<int>& v) {
    while (l < r) {
        int m = (l + r) / 2;
        if (v[m] >= x) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    return l;
}

int main() {
    int n;
    std::cin >> n;

    std::set<int> unique;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        unique.insert(x);
    }

    std::vector<int> diegoMarks(unique.begin(), unique.end());

    int k;
    std::cin >> k;

    std::vector<int> guestMarks(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> guestMarks[i];
    }

    for (int i = 0; i < guestMarks.size(); ++i) {
        int left = lBinSearch(0, diegoMarks.size(), guestMarks[i], diegoMarks);
        std::cout << left << '\n';
    }
}