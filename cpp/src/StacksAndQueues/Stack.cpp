#include "./Stack.h"
#include <iostream>
#include <limits.h>

Stack::Stack(int value) {
    Node* node = new Node(value);
    m_top = node;
    m_height = 1;
}

void Stack::push(int value) {
    Node* node = new Node(value);
    node->next = m_top;
    m_top = node;
    m_height++;
}

int Stack::pop() {
    if (m_height == 0) {
        return INT_MIN;
    } else {
        Node* temp = m_top;
        int poppedValue = m_top->value;
        m_top = m_top->next;
        delete temp;
        m_height--;
        return poppedValue;
    }
}

void Stack::printAll() {
    Node* temp = m_top;
    while (temp) {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

void Stack::printTop() const {
    if (!m_top) {
        return;
    }
    std::cout << "TOP:\t" << m_top->value << std::endl;
}

void Stack::printHeight() const {
    std::cout << "HEIGHT:\t" << m_height << std::endl;
}
