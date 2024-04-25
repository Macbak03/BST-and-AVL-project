#include <iostream>
#include "string"
#include "algorithm"
#include "fstream"
#include "AVL.h"
#include "BST.h"
#include "Action.h"

using namespace std;

int main() {
    string treeType;
    cout << "tree type>";
    cin >> treeType;
    if (treeType == "BST") {
        BST *bst = new BST();
        int insert = bst->insertNodeValues();
        if (insert != 0) {
            return insert;
        }
        Node *root = nullptr;
        root = bst->build(bst->getNodesValues(), root);
        Action action(root, treeType);
        int actionResult = action.handleAction();
        if (actionResult == 0) {
            cout << "Program exited with status: " << actionResult;
            return 0;
        }
    } else if (treeType == "AVL") {
        AVL *avl = new AVL();
        int insert = avl->insertNodeValues();
        if (insert != 0) {
            return insert;
        }
        avl->sort();
        avl->medianValue();
        Node *root = avl->build(avl->getNodesAmount(), avl->getNodesValues());
        Action action(root, treeType);
        int actionResult = action.handleAction();
        if (actionResult == 0) {
            cout << "Program exited with status: " << actionResult;
            cout << "\n";
            return 0;
        }
    } else {
        cout << "Invalid tree type";
    }

    return 0;
}
