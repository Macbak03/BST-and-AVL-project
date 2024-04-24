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
    void remove();
    void deleteTree();
    void exportTree(Node* node, std::string treeName);
    void rebalance();
    static void findMinMax(Node* node);

    void generateTikz(Node* node, std::ofstream& outFile);
};

