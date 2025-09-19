//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <string>
#include <vector>

int main() {
    int k;
    std::cin >> k;

    std::string inputLine;
    std::cin >> inputLine;

    std::vector<char> letters = {
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'
    };

    int maxLength = 0;
    for (int i = 0; i < letters.size(); ++i) {
        int left = 0;
        int countChar = 0;

        for (int right = 0; right < inputLine.size(); ++right) {
            if (inputLine[right] != letters[i]) {
                ++countChar;
            }

            while (countChar > k) {
                if (inputLine[left] != letters[i]) {
                    --countChar;
                }
                ++left;
            }

            maxLength = std::max(maxLength, right - left + 1);
        }
    }

    std::cout << maxLength;
}