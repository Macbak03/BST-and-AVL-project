#pragma once


#include "Tree.h"

class BST : public Tree{
public:
    BST();
    Node * insert(int value, Node* node);
    
    Node * build(const std::vector<int>& values, Node* root);
    std::vector<int> getNodesValues();
};

