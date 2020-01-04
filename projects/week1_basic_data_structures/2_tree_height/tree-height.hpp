#ifndef TREE_HEIGHT_H
#define TREE_HEIGHT_H
#include <vector>

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

void set_kernel_stack_size();
int findMaxHeight(const std::vector<Node>& nodes, int n);

#endif