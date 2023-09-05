#pragma once

#include "./Node.h"

class Stack {
private:
    Node* m_top;
    int   m_height;

public:
    Stack(int value);
    ~Stack();

    void push(int value);
    int  pop();

    void printAll();
    void printTop() const;
    void printHeight() const;
};
