//
// Created by SebastianZiółkowski on 25.11.2019.
//

#ifndef BINOMIALHEAP_FILLHEAPSERVICE_H
#define BINOMIALHEAP_FILLHEAPSERVICE_H

#include <iostream>
#include "../BinomialHeap.h"

void heapManualInsert(BinomialHeap *heap){
    int inputValue = 1;
    while (inputValue != 0) {
        std::cout << std::endl << "Insert:";
        std::cin >> inputValue;
        heap->insert(inputValue);
        std::cout << std::endl << std::endl << "Heap after insert " << inputValue << ".\n";
        heap->printHeap();
    }
}

#endif //BINOMIALHEAP_FILLHEAPSERVICE_H
