#include <iostream>
#include <limits>
#include <sstream>
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
   /* std::cout<<"value---"<<node->value<<"---value\n";
    for (int leftValue: leftValues) {
        std::cout<<leftValue<<" ";
    }
    std::cout<<"\n";
    for (int rightValue : rightValues) {
        std::cout<<rightValue<<" ";
    }
    std::cout<<"\n";*/
    if(!leftValues.empty()){
        node->left = build(leftValues.size(), leftValues);
    }
    if(!rightValues.empty()){
        node->right = build(rightValues.size(), rightValues);
    }
    return node;
}

int AVL::insertNodeValues()
{
    std::cout << "insert>";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string line;
    getline(std::cin, line);
    std::istringstream iss(line);
    int value, count = 0;

    while (iss >> value) {
        if (count < nodesAmount) {
            nodesValues.push_back(value);
            count++;
        } else {
            std::cerr << "Error: More numbers entered than allowed (" << nodesAmount << ").\n";
            return -1;
        }
    }
    if (count < nodesAmount) {
        std::cerr << "Error: Fewer numbers entered than required (" << nodesAmount << ").\n";
        return -1;
    }
    return 0;
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