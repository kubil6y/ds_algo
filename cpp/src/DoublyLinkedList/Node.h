#pragma once

class Node {
public:
    int   value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};
