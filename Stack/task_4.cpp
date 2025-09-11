//
// Created by Marat on 10.09.25.
//

#include <iostream>
#include <vector>

struct Stack {
    Stack* next;
    int value;
};

void push(Stack*& head, int value) {
    const auto newNode = new Stack{head, value};
    head = newNode;
}

void pop(Stack*& head) {
    if (head == nullptr) return;
    const auto temp = head->next;
    delete head;
    head = temp;
}

int top(Stack*& head) {
    if (head == nullptr) return 0;
    return head->value;
}

bool empty(Stack*& head) {
    return (head == nullptr);
}

bool check(Stack*& head, const std::vector<int>& vec) {
    if (vec.size() == 1) return true;

    std::vector<int> result;
    result.reserve(vec.size());

    int next = 2;
    push(head, vec[0]);
    for (size_t i = 1; i < vec.size(); ++i, ++next) {
        if (vec[i] > top(head)) {
            while (vec[i] > top(head) && head != nullptr) {
                result.push_back(top(head));
                pop(head);
            }
            push(head, vec[i]);
        } else if (vec[i] < top(head) && vec[i] < vec[next]) {
            result.push_back(vec[i]);
        } else {
            push(head, vec[i]);
        }
    }

    while (!empty(head)) {
        result.push_back(top(head));
        pop(head);
    }

    for (size_t i = 0; i < result.size() - 1; ++i) {
        if (result[i] > result[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    Stack* s = nullptr;

    std::cout << (check(s, vec) ? "YES" : "NO") << '\n';
}