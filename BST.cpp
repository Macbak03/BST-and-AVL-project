#include <iostream>
#include "BST.h"

BST::BST() {
    std::cout << " nodes>";
    std::cin >> nodesAmount;
}

Node *BST::insert(int value, Node *node) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->value) {
        node->left = insert(value, node->left);
    } else if (value > node->value) {
        node->right = insert(value, node->right);
    } else {
        return node;
    }

    return node;
}


Node * BST::build(const std::vector<int> &values, Node *root) {
    std::cout<<"inserting: ";
    for (int value: values) {
        root = insert(value, root);
        if(value != values[values.size()-1]){
            std::cout<<value<<", ";
        } else {
            std::cout<<value<<std::endl;
        }
    }
    return root;
}

std::vector<int> BST::getNodesValues() {
    return nodesValues;
}
