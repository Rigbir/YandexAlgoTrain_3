//
// Created by Marat on 19.09.25.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

int daySeconds = 24 * 60 * 60;

int toSeconds(int h, int m, int s) {
    return 60 * 60 * h + 60 * m + s;
}

std::string toStr(int number) {
    if (number < 10) {
        return "0" + std::to_string(number);
    }
    return std::to_string(number);
}

std::string toTimeFormat(int time) {
    while (time < 0) time += daySeconds;
    while (time >= daySeconds) time -= daySeconds;

    int h = time / 3600;
    int m = (time % 3600) / 60;
    int s = time % 60;

    return toStr(h) + ":" + toStr(m) + ":" + toStr(s);
}

int parseTime(const std::string& time) {
    std::stringstream ss(time);
    int h, m, s;
    char sep1, sep2;
    ss >> h >> sep1 >> m >> sep2 >> s;
    return toSeconds(h, m, s);
}

float getTime(int start, int end) {
    int delta = end - start;
    if (delta < 0) {
        delta += daySeconds;
    }
    return static_cast<int>(std::round(delta / 2.0));
}

std::string SNTP(const std::string& a, const std::string& b, const std::string& c) {
    int userStart = parseTime(a);
    int server = parseTime(b);
    int userStop = parseTime(c);

    int time = getTime(userStart, userStop);
    int result = server + time;

    return toTimeFormat(result);
}

int main() {
    std::string a, b, c;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    std::getline(std::cin, c);

    std::cout << SNTP(a, b, c);
}