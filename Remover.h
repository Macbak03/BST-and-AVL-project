#pragma once

#include "Tree.h"
#include <vector>

class Remover {
public:
    explicit Remover(Node* root);
    Node* startRemove(const std::string& treeType, std::vector<int>* keys);
private:
    Node* root;
    Node* remove(Node* node, int key);
    Node* findMin(Node* node);
};

