//
// Created by SebastianZiółkowski on 24.11.2019.
//

#ifndef BINOMIALHEAP_BINOMIALHEAP_H
#define BINOMIALHEAP_BINOMIALHEAP_H


using namespace std;

struct node {

    int key;
    int grade;
    node *parent, *child, *next;
};

class BinomialHeap {
private:
    node *head;

    node *CreateNode(int);

    void link_tree(node *, node *);

    node *merge_tree(node *, node *);

    node *union_tree(node *, node *);

    void printTree(node *);

public:
    void printHeap();

    BinomialHeap();

    void insert(int);

    bool search(int);

    void join(BinomialHeap *);

    node *getMin();

    node *B_head();
};

#endif //BINOMIALHEAP_BINOMIALHEAP_H
