//
// Created by SebastianZiółkowski on 22.11.2019.
//

#ifndef LICENCJATPROGRAM_TIMERSERVICE_H
#define LICENCJATPROGRAM_TIMERSERVICE_H

#include <ctime>

using namespace std;

class TimerService {
private:
    std::clock_t start;
    double duration;

public:
    TimerService() {
        duration = 0;
        start = std::clock();
    }

    double CurrentTime(){
        return (std::clock() - start) / (double) CLOCKS_PER_SEC;
    }

    ~TimerService() {
        duration = CurrentTime();
        if (duration < 1) {
            std::cout << std::endl << "Total time: " << duration << " second";
        } else std::cout << std::endl << "Total time: " << duration << " seconds";
    }


};


#endif //LICENCJATPROGRAM_TIMERSERVICE_H
