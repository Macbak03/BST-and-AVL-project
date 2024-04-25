#include "Balancer.h"
#include <cmath>

Balancer::Balancer() = default;

Node *Balancer::rotateRight(Node *rotator) {
    Node *pivot = rotator->left;
    rotator->left = pivot->right;
    pivot->right = rotator;
    return pivot;
}

Node *Balancer::rotateLeft(Node *rotator) {
    Node *pivot = rotator->right;
    rotator->right = pivot->left;
    pivot->left = rotator;
    return pivot;
}

Node *Balancer::makeVine(Node *node) {
    if (node->left == nullptr && node->right == nullptr) {
        return node;
    }
    if (node->left == nullptr) {
        node->right = makeVine(node->right);
    } else {
        node = rotateRight(node);
        node = makeVine(node);
    }
    return node;
}

Node *Balancer::balanceTree1stStep(Node *node, int w) {
    if (w > 0) {
        node = rotateLeft(node);
        node->right = balanceTree1stStep(node->right, --w);
    } else {
        return node;
    }
    return node;
}

Node *Balancer::balanceTree(Node *node, int y) {
    if(y > 1){
        node = rotateLeft(node);
        node->right = balanceTree(node->right, y/2);
    } else {
        return node;
    }
    return node;
}

int Balancer::countNodes(Node *node) {
    int count = 0;
    while (node != nullptr) {
        count++;
        node = node->right;
    }
    return count;
}


