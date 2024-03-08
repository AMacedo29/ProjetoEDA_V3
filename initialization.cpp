#include <iostream>
#include "utils.h"
#import "section.h"


int initialize_wharehouse(){
    srand(time(nullptr));  // renew seed to random number
    for (int i = 0; i < calculateRancomNumber(7,10); ++i) {
        char id = i+65;
        int random_capacity = calculateRancomNumber(3,6);
        Section section{
            id,
            random_capacity,
            "category"
        };
        printSection(section);
    };
    return 0;
}