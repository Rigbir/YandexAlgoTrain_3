//
// Created by Marat on 10.09.25.
//

#include <iostream>
#include <vector>

struct Stack {
    Stack* next;
    std::pair<int, int> value;
};

void push(Stack*& head, const std::pair<int, int>& value) {
    const auto newNode = new Stack{head, value};
    head = newNode;
}

void pop(Stack*& head) {
    if (head == nullptr) return;
    const auto temp = head->next;
    delete head;
    head = temp;
}

std::pair<int, int> top(Stack*& head) {
    if (head == nullptr) return {0, 0};
    return {head->value.first, head->value.second};
}

std::vector<int> city(Stack*& head, const std::vector<std::pair<int, int>>& vec) {
    std::vector<int> result(vec.size(), 0);

    push(head, vec[0]);
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i].first < top(head).first) {
            while (vec[i].first < top(head).first) {
                result[top(head).second] = vec[i].second;
                pop(head);
            }
            push(head, vec[i]);
        } else {
            push(head, vec[i]);
        }
    }

    for (size_t i = 0; i < result.size(); ++i) {
        if (result[i] == 0) {
            result [i] = -1;
        }
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> vec;
    vec.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        vec.push_back(std::make_pair(x, i));
    }

    Stack* s = nullptr;

    std::vector<int> result = city(s, vec);
    for (const auto i : result) {
        std::cout << i << ' ';
    }
}