//
// Created by Marat on 10.09.25.
//

#include <iostream>
#include <string>

struct Stack {
    Stack* next;
    char value;
};

void push(Stack*& head, const char value) {
    const auto newNode = new Stack{head, value};
    head = newNode;
}

void pop(Stack*& head) {
    const auto temp = head->next;
    delete head;
    head = temp;
}

char top(Stack*& head) {
    if (head == nullptr) return '\0';
    return head->value;
}

bool empty(Stack*& head) {
    if (head == nullptr) return true;
    return false;
}

bool check(Stack*& head, const std::string& line) {
    for (const char c : line) {
        if (c == '(' || c == '[' || c == '{') {
            push(head, c);
        } else if (c == ')') {
            if (empty(head) || top(head) != '(') return false;
            pop(head);
        } else if (c == ']') {
            if (empty(head) || top(head) != '[') return false;
            pop(head);
        } else if (c == '}') {
            if (empty(head) || top(head) != '{') return false;
            pop(head);
        }
    }

    return empty(head);
}

int main() {
    Stack* s = nullptr;

    std::string inputLine;
    std::cin >> inputLine;

    std::cout << (check(s, inputLine) ? "yes" : "no") << '\n';
}