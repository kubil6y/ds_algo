#pragma once

#include "./Node.h"

class Queue {
private:
    Node* m_first;
    Node* m_last;
    int   m_length;

public:
    Queue(int value);

    void enqueue(int value);
    int  dequeue();

    void printAll();
    void printFirst() const;
    void printLast() const;
    void printLength() const;
};
