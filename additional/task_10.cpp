//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <map>

int main() {
    std::string inputLine;
    std::cin >> inputLine;

    std::map<char, long long> countSymbols;
    for (int i = 0; i < inputLine.size(); ++i) {
        countSymbols[inputLine[i]] += (i + 1) * (inputLine.size() - i);
    }

    for (const auto [ch, cnt] : countSymbols) {
        std::cout << ch << ": " << cnt << '\n';
    }
}