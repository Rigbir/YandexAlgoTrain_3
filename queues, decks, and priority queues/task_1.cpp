//
// Created by Marat on 12.09.25.
//

#include <iostream>
#include <string>
#include <sstream>

struct Node {
    Node* next;
    int value;
};

struct Queue {
    Node* head;
    Node* tail;
    size_t sz;
};

std::string push(Queue*& q, const int value) {
    const auto temp = new Node{nullptr, value};

    if (q == nullptr) {
        q = new Queue{temp, temp, 0};
    } else if (q->head == nullptr) {
        q->head = temp;
        q->tail = temp;
    } else {
        q->tail->next = temp;
        q->tail = temp;
    }
    ++q->sz;

    return "ok";
}

std::string pop(Queue*& q) {
    if (q == nullptr || q->head == nullptr) return "error";

    const int delValue = q->head->value;
    const auto temp = q->head->next;
    delete q->head;
    q->head = temp;

    if (q->head == nullptr) {
        q->tail = nullptr;
    }

    --q->sz;

    return std::to_string(delValue);
}

std::string front(Queue*& q) {
    if (q == nullptr || q->head == nullptr) return "error";
    return std::to_string(q->head->value);
}

size_t size(Queue*& q) {
    if (q == nullptr) return 0;
    return q->sz;
}

std::string clear(Queue*& q) {
    if (q != nullptr) {
        while (q->head != nullptr) {
            const auto temp = q->head->next;
            delete q->head;
            q->head = temp;
        }
        q->tail = nullptr;
        q->sz = 0;
    }
    return "ok";
}

int main() {
    Queue* q = nullptr;

    std::string inputLine;

    while (std::getline(std::cin, inputLine)) {
        std::istringstream iss(inputLine);
        std::string command;
        iss >> command;

        if (command == "push") {
            if (int n; iss >> n) {
                std::cout << push(q, n) << '\n';
            }
        } else if (command == "pop") {
            std::cout << pop(q) << '\n';
        } else if (command == "front") {
            std::cout << front(q) << '\n';
        } else if (command == "size") {
            std::cout << size(q) << '\n';
        } else if (command == "clear") {
            std::cout << clear(q) << '\n';
        } else if (command == "exit") {
            std::cout << "bye" << '\n';
            break;
        } else {
            break;
        }
    }
}