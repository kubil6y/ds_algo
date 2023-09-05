#include "./DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList(int value) {
    Node* node = new Node(value);
    m_head = node;
    m_tail = node;
    m_length = 1;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* temp = m_head;
    while (m_head) {
        m_head = m_head->next;
        delete temp;
        temp = m_head;
    }
}

Node* DoublyLinkedList::get(int index) const {
    if (index < 0 || index >= m_length) {
        return nullptr;
    }

    Node* temp;
    if (index < m_length / 2) {
        temp = m_head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    } else {
        temp = m_tail;
        for (int i = m_length - 1; i > index; i--) {
            temp = temp->prev;
        }
        return temp;
    }
}

bool DoublyLinkedList::set(int index, int value) {
    Node* node = this->get(index);
    if (!node) {
        return false;
    } else {
        node->value = value;
        return true;
    }
}

bool DoublyLinkedList::insert(int index, int value) {
    if (index < 0 || index > m_length) {
        return false;
    }
    if (index == 0) {
        prepend(value);
        return true;
    }
    if (index == m_length) {
        append(value);
        return true;
    }
    Node* newNode = new Node(value);
    Node* before = get(index - 1);
    Node* after = before->next;
    newNode->prev = before;
    newNode->next = after;
    before->next = newNode;
    after->prev = newNode;
    m_length++;
    return true;
}

void DoublyLinkedList::append(int value) {
    Node* node = new Node(value);
    if (!m_head) {
        m_head = node;
        m_tail = node;
    } else {
        m_tail->next = node;
        node->prev = m_tail;
        m_tail = node;
    }
    m_length++;
}

void DoublyLinkedList::prepend(int value) {
    Node* node = new Node(value);
    if (!m_head) {
        m_head = node;
        m_tail = node;
    } else {
        m_head->prev = node;
        node->next = m_head;
        m_head = node;
    }
    m_length++;
}

void DoublyLinkedList::deleteNode(int index) {
    if (index < 0 || index >= m_length) {
        return;
    }
    if (index == 0) {
        return deleteFirst();
    }
    if (index == m_length - 1) {
        return deleteLast();
    }
    Node* node = get(index);
    Node* before = node->prev;
    Node* after = node->next;
    before->next = after;
    after->prev = before;
    delete node;
    m_length--;
}

void DoublyLinkedList::deleteFirst() {
    if (!m_head) {
        return;
    }
    Node* temp = m_head;
    if (m_length == 1) {
        m_head = nullptr;
        m_tail = nullptr;
    } else {
        m_head = m_head->next;
        m_head->prev = nullptr;
    }
    delete temp;
    m_length--;
}

void DoublyLinkedList::deleteLast() {
    if (!m_tail) {
        return;
    }
    Node* temp = m_tail;
    if (m_length == 1) {
        m_head = nullptr;
        m_tail = nullptr;
    } else {
        m_tail = m_tail->prev;
        m_tail->next = nullptr;
    }
    delete temp;
    m_length--;
}

void DoublyLinkedList::printAll() {
    Node* temp = m_head;
    while (temp) {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

void DoublyLinkedList::printHead() const {
    if (!m_head) {
        return;
    }
    std::cout << "HEAD:\t" << m_head->value << std::endl;
}

void DoublyLinkedList::printTail() const {
    if (!m_tail) {
        return;
    }
    std::cout << "TAIL:\t" << m_tail->value << std::endl;
}

void DoublyLinkedList::printLength() const {
    std::cout << "LENGTH:\t" << m_length << std::endl;
}
