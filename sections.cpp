#include <iostream>
#include "sections.h"


void printSection(Section& section){
    std::cout << " Section " << std::endl;
    std::cout << "ID: " << section.id << std::endl;
    std::cout << "Capacity: " << section.capacity << std::endl;
    std::cout << "Category: " << section.category << std::endl;
}
//ID único, capacidade máxima e categoria