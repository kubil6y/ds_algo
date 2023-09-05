#include "./LinkedList.h"
#include <iostream>

LinkedList::LinkedList(int value) {
    Node* newNode = new Node(value);
    m_head = newNode;
    m_tail = newNode;
    m_length = 1;
}

LinkedList::~LinkedList() {
    // NOTE: m_head, m_tail, m_length will be deleted automatically
    // LinkedList does not know how to delete Node*
    Node* temp = m_head;
    while (m_head) {
        m_head = m_head->next;
        delete temp;
        temp = m_head;
    }
}

void LinkedList::reverse() {
    if (!m_head) {
        return;
    }

    Node* temp = m_head;
    m_head = m_tail;
    m_tail = temp;

    Node* before = nullptr;
    Node* after = nullptr;
    for (int i = 0; i < m_length; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}

Node* LinkedList::get(int index) const {
    if (m_length < 0 || index >= m_length) {
        return nullptr;
    }
    Node* node = m_head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

bool LinkedList::set(int index, int value) {
    Node* node = get(index);
    if (!node) {
        return false;
    }
    node->value = value;
    return true;
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (!m_tail) {
        m_head = newNode;
        m_tail = newNode;
    } else {
        m_tail->next = newNode;
        m_tail = newNode;
    }
    m_length++;
}

void LinkedList::prepend(int value) {
    Node* newNode = new Node(value);
    if (!m_head) {
        m_head = newNode;
        m_tail = newNode;
    } else {
        newNode->next = m_head;
        m_head = newNode;
    }
    m_length++;
}

bool LinkedList::insert(int index, int value) {
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
    Node* temp = get(index - 1);
    newNode->next = temp->next;
    temp->next = newNode;
    m_length++;
    return true;
}

void LinkedList::deleteNode(int index) {
    if (index < 0 || index >= m_length) {
        return;
    }
    if (index == 0) {
        return deleteFirst();
    }
    if (index == m_length - 1) {
        return deleteLast();
    }
    Node* pre = get(index - 1);
    Node* node = pre->next;
    pre->next = node->next;
    m_length--;
    delete node;
}

void LinkedList::deleteFirst() {
    if (m_length == 0) {
        return;
    }
    Node* temp = m_head;
    if (m_length == 1) {
        m_head = nullptr;
        m_tail = nullptr;
    } else {
        m_head = m_head->next;
    }
    delete temp;
    m_length--;
}

void LinkedList::deleteLast() {
    if (m_length == 0) {
        return;
    }

    if (m_length == 1) {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_length--;
        return;
    }

    Node* temp = m_head;
    Node* pre = m_head;
    while (temp->next) {
        pre = temp;
        temp = temp->next;
    }
    m_tail = pre;
    m_tail->next = nullptr;
    m_length--;
    delete temp;
}

void LinkedList::printAll() {
    Node* temp = m_head;
    while (temp) {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

void LinkedList::printHead() const {
    if (!m_head) {
        return;
    }
    std::cout << "HEAD:\t" << m_head->value << std::endl;
}

void LinkedList::printTail() const {
    if (!m_tail) {
        return;
    }

    std::cout << "TAIL:\t" << m_tail->value << std::endl;
}

void LinkedList::printLength() const {
    std::cout << "LENGTH:\t" << m_length << std::endl;
}
