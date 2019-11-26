#include <iostream>
#include <vector>
#include "src/services/TimerService.h"
#include "src/BinomialHeap.h"
#include "src/services/FillHeapService.h"

int main() {
    auto *timerService = new TimerService();
    auto *heap = new BinomialHeap();

    heapManualInsert(heap);

    std::cout << std::endl << "Min key in heap: " << heap->getMin()->key;

    delete timerService;
    return 0;
}