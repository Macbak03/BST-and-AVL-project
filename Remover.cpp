#include <iostream>
#include "Remover.h"

using namespace std;

Remover::Remover(Node *root) : root(root){}

Node *Remover::startRemove(const string& treeType, vector<int>* keys) {

    if (treeType == "BST") {
        for (int key: *keys) {
            root = remove(root, key);
        }
    } else {
        for (int key: *keys) {
            root = remove(root, key);
            //balance
        }
    }
    return root;
}

Node *Remover::remove(Node *node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {

        if (node->left == nullptr) {
            Node *tmp = node->right;
            delete node;
            return tmp;
        } else if (node->right == nullptr) {
            Node *tmp = node->left;
            delete node;
            return tmp;
        }

        Node *tmp = findMin(node->right);
        node->key = tmp->key;
        node->right = remove(node->right, tmp->key);
    }
    return node;
}

Node *Remover::findMin(Node *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
