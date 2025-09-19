//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<char, int> symbols;
    std::string inputLine;

    while (std::getline(std::cin, inputLine)) {
        for (auto c : inputLine) {
            if (c != ' ') {
                ++symbols[c];
            }
        }
    }

    int maxHeight = 0;
    for (auto [ch, cnt] : symbols) {
        if (cnt > maxHeight) {
            maxHeight = cnt;
        }
    }

    for (int i = maxHeight; i > 0; --i) {
        for (auto [ch, cnt] : symbols) {
            std::cout << (cnt >= i ? '#' : ' ');
        }
        std::cout << '\n';
    }

    for (auto [ch, cnt] : symbols) {
        std::cout << ch; 
    }
}
