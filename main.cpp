#include <iostream>
#include "string"
#include "algorithm"
#include "fstream"
#include "AVL.h"
#include "BST.h"

using namespace std;

int checkTreeType(const string &treeType) {
    if (treeType == "BST") {
        return 0;
    } else if (treeType == "AVL") {
        return 1;
    } else {
        return -1;
    }
}

void generateTikz(Node* root, std::ofstream& outFile) {
    if (root == nullptr) {
        return;
    }

    outFile << "\\node {" << root->value << "}\n";

    if (root->left != nullptr) {
        outFile << "child {" << std::endl;
        generateTikz(root->left, outFile);
        outFile << "}\n";
    }

    if (root->right != nullptr) {
        outFile << "child {" << std::endl;
        generateTikz(root->right, outFile);
        outFile << "}\n";
    }
}


int main() {
    string treeType;
    cout << "tree type>";
    cin >> treeType;
    int treeTypeValidation = checkTreeType(treeType);
    switch (treeTypeValidation) {
        case 0: { //BST
            BST *bst = new BST();
            int insert = bst->insertNodeValues();
            if(insert == -1){
                break;
            }
            Node *root = nullptr;
            root = bst->build(bst->getNodesValues(), root);

            std::ofstream outFile("bst_tree.tex");
            if (!outFile.is_open()) {
                std::cerr << "Błąd: Nie można otworzyć pliku do zapisu." << std::endl;
                return 1;
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
            outFile << "\\node {" << root->value << "}\n";
            generateTikz(root, outFile);
            outFile << ";\n";
            outFile << "\\end{scope}\n";

            outFile << "\\end{tikzpicture}\n";
            outFile << "\\end{document}\n";

            outFile.close();

            break;
        }
        case 1: { //AVL
            AVL *avl = new AVL();
            int insert = avl->insertNodeValues();
            if (insert == -1) {
                break;
            }
            avl->sort();
            Node *root = avl->build(avl->getNodesAmount(), avl->getNodesValues());
            break;
        }
        default: {
            cout << "Invalid tree type";
            break;
        }
    }


    return 0;
}
