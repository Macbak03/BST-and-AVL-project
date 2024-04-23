#pragma once


#include "Tree.h"

class BST : public Tree{
public:
    BST();
    Node * insert(int value, Node* node);

    void build(const std::vector<int>& values, Node* root);
    std::vector<int> getNodesValues();
};

