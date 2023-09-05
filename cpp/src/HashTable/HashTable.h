#pragma once

#include "./Node.h"
#include <iostream>
#include <vector>

class HashTable {
private:
    static const int SIZE = 7;

    Node* m_dataMap[SIZE];

public:
    void printAll() const;
    int  hash(const std::string& key) const;
    void set(const std::string& key, int value);
    int  get(const std::string& key) const;

    std::vector<std::string> keys();
};
