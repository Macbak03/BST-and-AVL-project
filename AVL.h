#pragma once

#include "Tree.h"

class AVL : public Tree{
public:
    AVL();
    void sort();
    Node * build(int nodesAmount, std::vector<int> values);
    int insertNodeValues() override;

    int getNodesAmount();
    std::vector<int> getNodesValues();
    void medianValue();
private:
    static int getMedianIndex(int nodesAmount);
};

