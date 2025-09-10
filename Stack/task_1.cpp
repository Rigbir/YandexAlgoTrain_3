//
// Created by Marat on 10.09.25.
//

#include <iostream>
#include <sstream>
#include <string>

struct Stack {
    Stack* next;
    int value;
};

std::string push(Stack*& head, const int value) {
    const auto newNode = new Stack{head, value};
    head = newNode;
    return "ok";
}

std::string pop(Stack*& head) {
    if (head == nullptr) return "error";

    const int deleteValue = head->value;

    const auto temp = head->next;
    delete head;
    head = temp;

    return std::to_string(deleteValue);
}

std::string top(Stack*& head) {
    if (head == nullptr) return "error";
    return std::to_string(head->value);
}

size_t size(Stack* head) {
    if (head == nullptr) return 0;

    size_t i = 0;
    while (head != nullptr) {
        ++i;
        head = head->next;
    }

    return i;
}

std::string clear(Stack*& head) {
    while (head != nullptr) {
        const auto temp = head->next;
        delete head;
        head = temp;
    }
    return "ok";
}

int main() {
    Stack* s = nullptr;
    std::string inputLine;

    while (std::getline(std::cin, inputLine)) {
        std::istringstream iss(inputLine);
        std::string command;
        iss >> command;

        if (command == "push") {
            if (int n; iss >> n) {
                std::cout << push(s, n) << '\n';
            }
        } else if (command == "pop") {
            std::cout << pop(s) << '\n';
        } else if (command == "back") {
            std::cout << top(s) << '\n';
        } else if (command == "size") {
            std::cout << size(s) << '\n';
        } else if (command == "clear") {
            std::cout << clear(s) << '\n';
        } else if (command == "exit") {
            std::cout << "bye" << '\n';
            break;
        } else {
            break;
        }
    }
}