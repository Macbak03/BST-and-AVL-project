#include <iostream>
#include <limits>
#include <sstream>
#include "BST.h"

BST::BST() {
    std::cout << " nodes>";
    std::cin >> nodesAmount;
}

Node *BST::insert(int value, Node *node) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->value) {
        node->left = insert(value, node->left);
    } else if (value > node->value) {
        node->right = insert(value, node->right);
    } else {
        return node;
    }

    return node;
}

int BST::insertNodeValues()
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

Node * BST::build(const std::vector<int> &values, Node *root) {
    std::cout<<"inserting: ";
    for (int value: values) {
        root = insert(value, root);
        if(value != values[values.size()-1]){
            std::cout<<value<<", ";
        } else {
            std::cout<<value<<std::endl;
        }
    }
    return root;
}

std::vector<int> BST::getNodesValues() {
    return nodesValues;
}
