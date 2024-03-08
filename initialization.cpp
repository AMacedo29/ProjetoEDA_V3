#include <iostream>
#include "utils.h"
#import "sections.h"


void initialize_wharehouse(){
    srand(time(nullptr));  // renew seed to random number
    for (int i = 0; i < calculateRandomNumber(7, 10); ++i) {
        char id = i+65;
        int random_capacity = calculateRandomNumber(3, 6);
        Section section{
            id,
            random_capacity,
            "category"
        };
        printSection(section);
    };

}