#include <iostream>
#include <iomanip>
#include <limits>
#include <utility>
#include "fstream"
#include "Action.h"


using namespace std;

Action::Action(Node *root, string treeType) : root(root), treeType(std::move(treeType)) {}

int Action::handleAction() {
    string actionName;
    bool keepRunning = true;
    while (keepRunning) {
        cout << "action>";
        cin >> actionName;

        if (cin.eof()) {
            break;
        }

        int actionType = checkActionType(actionName);
        switch (actionType) {
            case 1: { //Help
                showHelp();
                break;
            }
            case 2: { //Print
                print();
                break;
            }
            case 3: { //Remove
                remove();
                break;
            }
            case 4: { //Delete
                deleteTree();
                break;
            }
            case 5: { //Export
                exportTree(root, treeType);
                break;
            }
            case 6: { //Rebalance
                rebalance();
                break;
            }
            case 7:{ //FindMinMax
                findMinMax(root);
                break;
            }
            case 8: { //Exit
                keepRunning = false;
                break;
            }
            default: {
                cout << "Invalid action. Type Help for action list.\n";
                break;
            }
        }
    }
    return 0;
}

int Action::checkActionType(const std::string &action) {
    if (action == "Help") {
        return 1;
    } else if (action == "Print") {
        return 2;
    } else if (action == "Remove") {
        return 3;
    } else if (action == "Delete") {
        return 4;
    } else if (action == "Export") {
        return 5;
    } else if (action == "Rebalance") {
        return 6;
    } else if(action == "FindMinMax") {
        return 7;
    } else if (action == "Exit") {
        return 8;
    } else {
        return -1;
    }
}

void Action::showHelp() {
    int width = 15;
    cout << left; // Align text to the left
    cout << setw(width) << "Help" << "Show this message\n";
    cout << setw(width) << "Print" << "Print the tree using In-order, Pre-order, Post-order\n";
    cout << setw(width) << "Remove" << "Remove elements from the tree\n";
    cout << setw(width) << "Delete" << "Delete the whole tree\n";
    cout << setw(width) << "Export" << "Export the tree to tikzpicture\n";
    cout << setw(width) << "Rebalance" << "Rebalance the tree\n";
    cout << setw(width) << "FindMinMax" << "Finds minimal and maximal value in the tree\n";
    cout << setw(width) << "Exit" << "Exits the program (same as Ctrl+D)\n";
}

void Action::print() {

}

void Action::remove() {

}

void Action::deleteTree() {

}

void Action::generateTikz(Node *node, ofstream &outFile) {
    if (node == nullptr) {
        return;
    }

    outFile << "\\node {" << node->value << "}\n";

    if (node->left != nullptr) {
        outFile << "child {" << std::endl;
        generateTikz(node->left, outFile);
        outFile << "}\n";
    }

    if (node->right != nullptr) {
        outFile << "child {" << std::endl;
        generateTikz(node->right, outFile);
        outFile << "}\n";
    }

}

void Action::exportTree(Node *node, string treeName) {
    string fileName = treeName.append("_tree.tex");
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
        return;
    }

    outFile << "\\documentclass{standalone}\n";
    outFile << "\\usepackage{tikz}\n";
    outFile << "\\begin{document}\n";
    outFile << "\\begin{tikzpicture}\n";
    outFile << "[every node/.style={circle, draw}]\n";

    outFile << "\\tikzset{level 1/.style={sibling distance=60mm}, "
            << "level 2/.style={sibling distance=30mm}, "
            << "level 3/.style={sibling distance=20mm}, "
            << "level 4/.style={sibling distance=10mm}}\n";
    outFile << "\\begin{scope}[every node/.style={circle,draw}, level distance=30mm]\n";
    outFile << "\\node {" << node->value << "}\n";
    generateTikz(node, outFile);
    outFile << ";\n";
    outFile << "\\end{scope}\n";

    outFile << "\\end{tikzpicture}\n";
    outFile << "\\end{document}\n";

    outFile.close();

    cout << "File " << fileName << " has been generated.\n";

}

void Action::rebalance() {

}

void Action::findMinMax(Node* node) {
    Node* nodeLeft = node;
    Node* nodeRight = node;
    int min = nodeLeft->value;
    int max = nodeRight->value;
    while (nodeLeft->left != nullptr){
        nodeLeft = nodeLeft->left;
        min = nodeLeft->value;
    }
    while (nodeRight->right != nullptr){
        nodeRight = nodeRight->right;
        max = nodeRight->value;
    }
    cout<<"Min: "<<min<<endl;
    cout<<"Max: "<<max<<endl;
}
