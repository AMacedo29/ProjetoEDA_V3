#include <iostream>
#include "utils.h"
#include "sections.h"


void initialize_wharehouse(){
    std::cout << "          *********************************************" << std::endl;
    std::cout << "          *** Armazem EDA  |  Total Faturacao" << "     " << "$" << " ***" << std::endl;
    std::cout << "          *********************************************" << std::endl;
    srand(time(nullptr));  // renew seed to random number
    for (int i = 0; i < calculateRandomNumber(7, 10); ++i) {
        char id = i+65;
        int random_capacity = calculateRandomNumber(3, 6);
        Section section{
            id,
            random_capacity
        };
        printSection(section);
        //printLista(section);
    };


}