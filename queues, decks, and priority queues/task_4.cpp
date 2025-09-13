//
// Created by Marat on 12.09.25.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void insert(std::vector<int>& heap, const int value) {
    heap.push_back(value);
    int pos = heap.size() - 1;

    while (pos > 0 && heap[pos] > heap[(pos - 1) / 2]) {
        std::swap(heap[pos], heap[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}

int extract(std::vector<int>& heap) {
    if (heap.size() < 1) {
        throw std::runtime_error("Heap is empty.");
    }

    int answer = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    int pos = 0;
    while (pos * 2 + 1 < heap.size()) {
        int indexMaxVal = pos * 2 + 1;
        if (heap[indexMaxVal] < heap[pos * 2 + 2]) {
            indexMaxVal = pos * 2 + 2;
        }
        if (heap[pos] < heap[indexMaxVal]) {
            std::swap(heap[pos], heap[indexMaxVal]);
            pos = indexMaxVal;
        } else {
            break;
        }
    }

    return answer;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<int> heap;
    for (int i = 0; i < n; ++i) {
        std::string inputLine;
        std::getline(std::cin, inputLine);
        std::istringstream iss(inputLine);
        std::string command;
        iss >> command;

        if (command == "0") {
            if (int value; iss >> value) {
                insert(heap, value);
            }
        } else if (command == "1") {
            std::cout << extract(heap) << '\n';
        }
    }
}
