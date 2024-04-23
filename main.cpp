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

    // Wypisywanie węzła
    outFile << "\\node {" << root->value << "}\n";

    // Wypisywanie lewego poddrzewa
    if (root->left != nullptr) {
        outFile << "child {" << std::endl;
        generateTikz(root->left, outFile);
        outFile << "}\n";
    }

    // Wypisywanie prawego poddrzewa
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
            bst->build(bst->getNodesValues(), root);

            std::ofstream outFile("bst_tree.tex");
            if (!outFile.is_open()) {
                std::cerr << "Błąd: Nie można otworzyć pliku do zapisu." << std::endl;
                return 1;
            }

            // Rozpoczęcie kodu TikZ
            outFile << "\\documentclass{standalone}\n";
            outFile << "\\usepackage{tikz}\n";
            outFile << "\\begin{document}\n";
            outFile << "\\begin{tikzpicture}\n";
            outFile << "[every node/.style={circle, draw}]\n";

            // Generowanie kodu TikZ dla drzewa BST
            generateTikz(root, outFile);

            // Zakończenie kodu TikZ
            outFile << ";\n";
            outFile << "\\end{tikzpicture}\n";
            outFile << "\\end{document}\n";

            // Zamknięcie pliku
            outFile.close();

            std::cout << "Plik bst_tree.tex został wygenerowany." << std::endl;

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
