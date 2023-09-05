#pragma once

#include "./Node.h"

// https://en.wikipedia.org/wiki/Binary_search_tree

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree();

    bool insert(int value);
    bool contains(int value);
};
