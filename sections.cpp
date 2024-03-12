#include <iostream>
#include "sections.h"


void printSection(Section& section){
    std::cout << " Seccao " << section.id << "  | " << " Categoria: " << "categoria" << "  | " << " Capacity: " << section.capacity << "  | "  << std::endl;
}
//ID único, capacidade máxima e categoria