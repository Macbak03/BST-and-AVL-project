#include "Tree.h"

class Balancer {
public:
    explicit Balancer();

    Node* makeVine(Node* node);

    Node* balanceTree1stStep(Node* node, int w);
    Node* balanceTree(Node* node, int y);

    static int countNodes(Node* node);

private:

    static Node* rotateRight(Node* rotator);
    static Node* rotateLeft(Node* rotator);


};

