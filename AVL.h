#pragma once

#include "Tree.h"

class AVL : public Tree{
public:
    AVL();
    //int insertNodeValues() override;
    void sort();
    Node * build(int nodesAmount, std::vector<int> values);

    int getNodesAmount();
    std::vector<int> getNodesValues();
private:
    static int getMedianIndex(int nodesAmount);
};

