#include <iostream>
#include "string"
#include "algorithm"
#include "fstream"
#include "AVL.h"
#include "BST.h"
#include "Action.h"

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
            Action action(root, treeType);
            int actionResult = action.handleAction();
            if(actionResult == 0){
                cout<<"Program exited with status: "<<actionResult;
                return 0;
            }
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
            Action action(root, treeType);
            int actionResult = action.handleAction();
            if(actionResult == 0){
                cout<<"Program exited with status: "<< actionResult;
                return 0;
            }
            break;
        }
        default: {
            cout << "Invalid tree type";
            break;
        }
    }


    return 0;
}
