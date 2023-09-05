#include "./Queue.h"
#include <iostream>
#include <limits.h>

Queue::Queue(int value) {
    Node* node = new Node(value);
    m_first = node;
    m_last = node;
    m_length = 1;
}

void Queue::enqueue(int value) {
    Node* node = new Node(value);
    if (m_length == 0) {
        m_first = node;
        m_last = node;
    } else {
        m_last->next = node;
        m_last = node;
    }
    m_length++;
}

int Queue::dequeue() {
    if (m_length == 0) {
        return INT_MIN;
    }

    Node* temp = m_first;
    int   dequeuedValue = m_first->value;
    if (m_length == 1) {
        m_first = nullptr;
        m_last = nullptr;
    } else {
        m_first = m_first->next;
    }
    delete temp;
    m_length--;
    return dequeuedValue;
}

void Queue::printAll() {
    Node* temp = m_first;
    while (temp) {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

void Queue::printFirst() const {
    if (m_first) {
        std::cout << "FIRST:\t" << m_first->value << std::endl;
    }
}

void Queue::printLast() const {
    if (m_last) {
        std::cout << "LAST:\t" << m_last->value << std::endl;
    }
}

void Queue::printLength() const {
    std::cout << "LENGTH:\t" << std::to_string(m_length) << std::endl;
}
