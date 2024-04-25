#include <iostream>
#include "algorithm"
#include "AVL.h"

AVL::AVL() {
    std::cout << " nodes>";
    std::cin >> nodesAmount;
}

void AVL::sort() {
    std::sort(nodesValues.begin(), nodesValues.end());
    std::cout << "Sorted: ";
    for (int i = 0; i < nodesAmount; ++i) {
        if (i == nodesAmount - 1) {
            std::cout << nodesValues[i] << "\n";
        } else {
            std::cout << nodesValues[i] << ", ";
        }
    }
}

Node *AVL::build(int nodesAmount, std::vector<int> values) {
    int medianIndex = getMedianIndex(nodesAmount);
    Node* node = new Node(values[medianIndex]);
    std::vector<int> leftValues(values.begin(), values.begin() + medianIndex);
    std::vector<int> rightValues(values.begin() + medianIndex + 1, values.end());
    if(!leftValues.empty()){
        node->left = build(leftValues.size(), leftValues);
    }
    if(!rightValues.empty()){
        node->right = build(rightValues.size(), rightValues);
    }
    return node;
}


int AVL::getMedianIndex(int nodesAmount) {
    int amount = nodesAmount;
    if (amount > 2) {
        return nodesAmount / 2;
    } else {
        return 0;
    }
}

int AVL::getNodesAmount() {
    return nodesAmount;
}

std::vector<int> AVL::getNodesValues() {
    return nodesValues;
}

void AVL::medianValue()
{
    std::cout << "Median: " << nodesValues[getMedianIndex(getNodesAmount())] << std::endl;
}