//
// Created by Marat on 10.09.25.
//

#include <iostream>
#include <string>
#include <cctype>

struct Stack {
    Stack* next;
    std::string value;
};

void push(Stack*& head, const std::string& value) {
    const auto newNode = new Stack{head, value};
    head = newNode;
}

void pop(Stack*& head) {
    const auto temp = head->next;
    delete head;
    head = temp;
}

int top(Stack*& head) {
    return std::stoi(head->value);
}

int calcExpression(Stack*& head, const std::string& line) {
    auto apply = [&](auto op){
        int operand1 = top(head); pop(head);
        int operand2 = top(head); pop(head);
        push(head, std::to_string(op(operand2, operand1)));
    };

    for (const auto c : line) {
        if (std::isdigit(c)) {
            push(head, std::to_string(c - '0'));
        } else {
            switch (c) {
                case '+': apply([](int a, int b) { return a + b; }); break;
                case '-': apply([](int a, int b) { return a - b; }); break;
                case '*': apply([](int a, int b) { return a * b; }); break;
                case '/': apply([](int a, int b) { return a / b; }); break;
            }
        }
    }

    return top(head);
}

int main() {
    Stack* s = nullptr;

    std::string inputLine;
    std::getline(std::cin, inputLine);

    std::string inputWithoutSpace;
    for (const auto c : inputLine) {
        if (c != ' ') {
            inputWithoutSpace += c;
        }
    }

    std::cout << calcExpression(s, inputWithoutSpace) << '\n';
}