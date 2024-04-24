#pragma once

#include <vector>

struct Node{
    Node* left;
    Node* right;
    int value;

    explicit Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree {
protected:
    int nodesAmount;
    std::vector<int> nodesValues;

public:
    virtual int insertNodeValues() = 0;
};

