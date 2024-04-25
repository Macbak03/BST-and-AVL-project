#pragma once

#include <string>
#include "Tree.h"

class Action {
public:
    Action(Node* root, std::string treeType);
    int handleAction();
private:
    Node* root;
    std::string treeType;
    static int checkActionType(const std::string& action);

    static void showHelp();
    void print();
    void startRemove();
    void deleteTree(Node* node);
    void exportTree(Node* node, std::string treeName);
    void rebalance();
    static void findMinMax(Node* node);

    void generateTikz(Node* node, std::ofstream& outFile);

    void printPreOrder(Node* node);
    void printPostOrder(Node* node);
    void printInOrder(Node* node);

    Node* findMin(Node* node);
    Node* remove(Node* node, int key);

    static Node* rotateRight(Node* rotator);
    static Node* rotateLeft(Node* rotator);
};

