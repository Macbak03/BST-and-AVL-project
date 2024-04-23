#include <iostream>
#include <limits>
#include <sstream>
#include "Tree.h"

int Tree::insertNodeValues() {
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
