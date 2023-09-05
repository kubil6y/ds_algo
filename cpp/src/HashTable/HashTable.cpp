#include "./HashTable.h"

void HashTable::printAll() const {
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << ":" << std::endl;
        if (m_dataMap[i]) {
            Node* temp = m_dataMap[i];
            while (temp) {
                std::cout << "   {" << temp->key << ", " << temp->value << "}"
                          << std::endl;
                temp = temp->next;
            }
        }
    }
}

int HashTable::hash(const std::string& key) const {
    int hash = 0;
    int randomPrimeNumber = 23; // for more randomness
    for (int i = 0; i < static_cast<int>(key.length()); i++) {
        int asciiValue = int(key[i]);
        hash = (hash + asciiValue * randomPrimeNumber) % SIZE;
    }
    return hash;
}

void HashTable::set(const std::string& key, int value) {
    int   index = hash(key);
    Node* newNode = new Node(key, value);
    if (!m_dataMap[index]) {
        m_dataMap[index] = newNode;
    } else {
        Node* temp = m_dataMap[index];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int HashTable::get(const std::string& key) const {
    int   index = hash(key);
    Node* temp = m_dataMap[index];
    while (temp) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return 0;
}

std::vector<std::string> HashTable::keys() {
    std::vector<std::string> allKeys;
    for (int i = 0; i < SIZE; i++) {
        Node* temp = m_dataMap[i];
        while (temp) {
            allKeys.push_back(temp->key);
            temp = temp->next;
        }
    }
    return allKeys;
}
