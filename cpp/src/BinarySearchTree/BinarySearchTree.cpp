#include "./BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() { root = nullptr; }

bool BinarySearchTree::insert(int value) {
    Node* newNode = new Node(value);
    if (!root) {
        root = newNode;
        return true;
    }
    Node* temp = root;
    while (true) {
        if (newNode->value == temp->value) {
            return false;
        }
        if (newNode->value < temp->value) {
            if (temp->left == nullptr) {
                temp->left = newNode;
                return true;
            }
            temp = temp->left;
        } else {
            if (temp->right == nullptr) {
                temp->right = newNode;
                return true;
            }
            temp = temp->right;
        }
    }
}

bool BinarySearchTree::contains(int value) {
    if (!root) {
        return false;
    }
    Node* temp = root;
    while (temp) {
        if (value < temp->value) {
            temp = temp->left;
        } else if (value > temp->value) {
            temp = temp->right;
        } else { // equal case
            return true;
        }
    }
    return false;
}
