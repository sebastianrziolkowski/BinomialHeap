#define SDL_MAIN_HANDLED

#include <iostream>
#include <vector>
#include "src/services/TimerService.h"
#include "src/BinomialHeap.h"
#include "src/services/FillHeapService.h"
#include "src/services/SDL_services/initSDL.h"
#include <SDL2/SDL.h>

int main() {
//    auto *timerService = new TimerService();
//    auto *heap = new BinomialHeap();
//    heapManualInsert(heap);
//    std::cout << std::endl << "Min key in heap: " << heap->getMin()->key;
//    delete timerService;
//    return 0;


    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;

    initializeSDL(window, screenSurface);


    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}