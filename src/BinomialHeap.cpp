//
// Created by SebastianZiółkowski on 24.11.2019.
//

#include <bits/stdc++.h>
#include "BinomialHeap.h"

using namespace std;

BinomialHeap::BinomialHeap() {
    head = NULL;

}

node *BinomialHeap::CreateNode(int x) {
    node *n = new node();
    n->key = x;
    n->parent = NULL;
    n->child = NULL;
    n->next = NULL;
    n->grade = 0;
    return n;
}


void BinomialHeap::insert(int x) {
    if (head) {
        node *aux = CreateNode(x);
        head = union_tree(head, aux);
    } else {

        head = (CreateNode(x));
    }

}


void BinomialHeap::link_tree(node *tree_1, node *tree_2) {
    tree_1->parent = tree_2;
    tree_1->next = tree_2->child;
    tree_2->child = tree_1;
    tree_2->grade = tree_1->grade + 1;
}

node *BinomialHeap::merge_tree(node *Heap_1, node *Heap_2) {
    node *head;
    node *It_heap1 = Heap_1;
    node *It_heap2 = Heap_2;
    node *tail;

    if (It_heap1->grade <= It_heap2->grade) {
        head = It_heap1;
        It_heap1 = Heap_1->next;
    } else {
        head = It_heap2;
        It_heap2 = Heap_2->next;
    }
    tail = head;

    while (It_heap1 != NULL && It_heap2 != NULL) {

        if (It_heap1->grade <= It_heap2->grade) {
            tail->next = It_heap1;
            It_heap1 = It_heap1->next;
        } else {
            tail->next = It_heap2;
            It_heap2 = It_heap2->next;
        }

        tail = tail->next;
    }

    if (It_heap1 != NULL) {
        tail->next = It_heap1;
    } else tail->next = It_heap2;

    return head;
}


node *BinomialHeap::union_tree(node *Heap_1, node *Heap_2) {

    node *Heap_list = merge_tree(Heap_1, Heap_2);
    if (Heap_list != NULL) {

        node *aux = Heap_list;
        node *next_aux = aux->next;
        node *prev_aux = NULL;

        while (next_aux != NULL) {
            if (aux->grade != next_aux->grade || (next_aux->next != NULL && next_aux->next->grade == aux->grade)) {
                prev_aux = aux;
                aux = next_aux;
            } else {
                if (aux->key <= next_aux->key) {
                    aux->next = next_aux->next;
                    link_tree(next_aux, aux);

                } else {
                    if (prev_aux == NULL) Heap_list = next_aux;
                    else prev_aux->next = next_aux;
                    link_tree(aux, next_aux);
                    aux = next_aux;
                }
            }
            next_aux = aux->next;
        }
    }
    return Heap_list;
}

void BinomialHeap::join(BinomialHeap *h1) {
    union_tree(head, h1->head);
    head = NULL;
}


bool BinomialHeap::search(int x) {
    node *currPtr = head;
    while (currPtr != nullptr) {
        queue<node *> q;
        q.push(currPtr);
        while (!q.empty()) {
            node *p = q.front();
            q.pop();
            if (p->key == x) {

                return true;
            }
            if (p->child != nullptr) {
                node *tempPtr = p->child;
                while (tempPtr != nullptr) {
                    q.push(tempPtr);
                    tempPtr = tempPtr->next;
                }
            }
        }
        currPtr = currPtr->next;
    }

    return false;
}

void BinomialHeap::printTree(node *h) {
    while (h) {
        std::cout << std::endl
                  << "|key:" << h->key
                  << ", grade:" << h->grade;
        if (h->parent != NULL) {
            std::cout << ", parent:" << h->parent->key;
        }
        if (h->child != NULL) {
            std::cout << ", child:" << h->child->key;
        }
        if (h->next != NULL) {
            std::cout << ", next:" << h->next->key;
        }
        std::cout << "|";
        this->printTree(h->child);
        h = h->next;
    }
}

void BinomialHeap::printHeap() {
    this->printTree(this->head);
}

node *BinomialHeap::B_head() {
    return head;
}
