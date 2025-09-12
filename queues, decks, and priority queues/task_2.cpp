//
// Created by Marat on 12.09.25.
//

#include <iostream>
#include <string>

struct Node {
    Node* next;
    int value;
};

struct Queue {
    Node* head;
    Node* tail;
    size_t sz;
};

void push(Queue*& q, const int value) {
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
}

void pop(Queue*& q) {
    if (q == nullptr || q->head == nullptr) return;

    const auto temp = q->head->next;
    delete q->head;
    q->head = temp;
    if (q->head == nullptr) {
        q->tail = nullptr;
    }
    --q->sz;
}

int front(Queue*& q) {
    if (q == nullptr || q->head == nullptr) {
        throw std::runtime_error("Queue is empty");
    }
    return q->head->value;
}

void moveCards(Queue*& winner, Queue*& firstQueue, Queue*& secondQueue) {
    push(winner, front(firstQueue));
    push(winner, front(secondQueue));
    pop(firstQueue);
    pop(secondQueue);
}

std::string drunkard(Queue*& firstQueue, Queue*& secondQueue) {
    int steps = 0;

    while (firstQueue->head != nullptr && secondQueue->head != nullptr) {
        if (steps > 1e7) {
            std::cout << "botva" << '\n';
            break;
        }

        const int f = front(firstQueue);
        const int s = front (secondQueue);

        if ((f == 0 && s == 9) || (f > s && !(f == 9 && s == 0))) {
            moveCards(firstQueue, firstQueue, secondQueue);
        } else {
            moveCards(secondQueue, firstQueue, secondQueue);
        }

        ++steps;
    }

    return (firstQueue->head == nullptr ? "second " : "first ") + std::to_string(steps);
}

int main() {
    std::string firstPlayer, secondPlayer;

    std::getline(std::cin, firstPlayer);
    std::getline(std::cin, secondPlayer);

    Queue* firstPlayerQueue = nullptr;
    for (const auto c : firstPlayer) {
        if (c != ' ' && std::isdigit(c)) {
            push(firstPlayerQueue, c - '0');
        }
    }

    Queue* secondPlayerQueue = nullptr;
    for (const auto c : secondPlayer) {
        if (c != ' ' && std::isdigit(c)) {
            push(secondPlayerQueue, c - '0');
        }
    }

    std::cout << drunkard(firstPlayerQueue, secondPlayerQueue) << '\n';
}