//
// Created by Marat on 12.09.25.
//

#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

struct Node {
    Node* next;
    Node* prev;
    int value;
};

struct Deque {
    Node* head;
    Node* tail;
    size_t sz;
};

enum class Position { FRONT, BACK };

std::string insert_node(Deque*& d, const int value, Position pos) {
    const auto temp = new Node{nullptr, nullptr, value};

    if (d == nullptr) {
        d = new Deque{temp, temp, 1};
        return "ok";
    }

    if (d->head == nullptr) {
        d->head = temp;
        d->tail = temp;
    } else if (pos == Position::FRONT) {
        temp->next = d->head;
        d->head->prev = temp;
        d->head = temp;
    } else if (pos == Position::BACK) {
        temp->prev = d->tail;
        d->tail->next = temp;
        d->tail = temp;
    }
    ++d->sz;

    return "ok";
}

std::string delete_node(Deque*& d, Position pos) {
    if (d == nullptr || d->head == nullptr) return "error";

    int delValue;
    if (pos == Position::FRONT) {
        delValue = d->head->value;
        const auto temp = d->head->next;
        delete d->head;
        d->head = temp;
        if (d->head != nullptr) {
            d->head->prev = nullptr;
        } else {
            d->tail = nullptr;
        }
    } else if (pos == Position::BACK) {
        delValue = d->tail->value;
        const auto temp = d->tail->prev;
        delete d->tail;
        d->tail = temp;
        if (d->tail != nullptr) {
            d->tail->next = nullptr;
        } else {
            d->head = nullptr;
        }
    }
    --d->sz;

    return std::to_string(delValue);
}

std::string push_front(Deque*& d, const int value) {
    return insert_node(d, value, Position::FRONT);
}

std::string push_back(Deque*& d, const int value) {
    return insert_node(d, value, Position::BACK);
}

std::string pop_front(Deque*& d) {
    return delete_node(d, Position::FRONT);
}

std::string pop_back(Deque*& d) {
    return delete_node(d, Position::BACK);
}

std::string front(Deque*& d) {
    if (d == nullptr || d->head == nullptr) return "error";
    return std::to_string(d->head->value);
}

std::string back(Deque*& d) {
    if (d == nullptr || d->tail == nullptr) return "error";
    return std::to_string(d->tail->value);
}

size_t size(Deque*& d) {
    if (d == nullptr || d->head == nullptr) return 0;
    return d->sz;
}

std::string clear(Deque*& d) {
    if (d != nullptr) {
        while (d->head != nullptr) {
            const auto temp = d->head->next;
            delete d->head;
            d->head = temp;
        }
        d->tail = nullptr;
        d->sz = 0;
    }

    return "ok";
}

int main() {
    Deque* d = nullptr;
    std::string inputLine;

    std::map<std::string, std::function<void()>> commandsNoArg{
            {"pop_front", [&]() { std::cout << pop_front(d) << '\n'; }},
            {"pop_back",  [&]() { std::cout << pop_back(d)  << '\n'; }},
            {"front",     [&]() { std::cout << front(d)     << '\n'; }},
            {"back",      [&]() { std::cout << back(d)      << '\n'; }},
            {"size",      [&]() { std::cout << size(d)      << '\n'; }},
            {"clear",     [&]() { std::cout << clear(d)     << '\n'; }},
            {"exit",      [&]() { std::cout << "bye\n"; exit(0); }}
    };

    while (std::getline(std::cin, inputLine)) {
        std::istringstream iss(inputLine);
        std::string command;
        iss >> command;

        if (command == "push_front") {
            if (int n; iss >> n && size(d) < 100) {
                std::cout << push_front(d, n) << '\n';
            }
        } else if (command == "push_back") {
            if (int n; iss >> n && size(d) < 100) {
                std::cout << push_back(d, n) << '\n';
            }
        } else if (commandsNoArg.contains(command)) {
            commandsNoArg[command]();
        } else {
            break;
        }
    }
}