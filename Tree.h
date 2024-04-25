#pragma once

#include <vector>

struct Node{
    Node* left;
    Node* right;
    int key;

    explicit Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

class Tree {
protected:
    int nodesAmount;
    std::vector<int> nodesValues;

public:
    virtual int insertNodeValues();
};

