//
// Created by Marat on 12.09.25.
//

#include <iostream>
#include <vector>

void heapify(std::vector<int>& heap, const size_t i, const size_t size) {
    size_t largest = i;
    const size_t left = largest * 2 + 1;
    const size_t right = largest * 2 + 2;

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        heapify(heap, largest, size);
    }
}

std::vector<int> heapSort(std::vector<int>& heap) {
    for (int i = heap.size() - 1 / 2; i >= 0; --i) {
        heapify(heap, i, heap.size());
    }

    for (int i = heap.size() - 1; i >= 0; --i) {
        std::swap(heap[0], heap[i]);
        heapify(heap, 0, i);
    }

    return heap;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    v = heapSort(v);

    for (const auto i : v) {
        std::cout << i << ' ';
    }
}