#pragma once

#include "./Node.h"

class LinkedList {
private:
    Node* m_head;
    Node* m_tail;
    int   m_length;

public:
    LinkedList(int value);
    ~LinkedList();

    Node* get(int index) const;
    bool  set(int index, int value);
    void  append(int value);
    void  prepend(int value);
    bool  insert(int index, int value);
    void  deleteNode(int index);
    void  deleteFirst();
    void  deleteLast();

    void reverse(); // o_o

    void printAll();
    void printHead() const;
    void printTail() const;
    void printLength() const;
};
