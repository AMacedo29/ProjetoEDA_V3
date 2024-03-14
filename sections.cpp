#include <iostream>
#include "sections.h"


void printSection(Section& section){
    std::cout << " Seccao " << section.id << "  | " << " Categoria: " << "categoria" << "  | " << " Capacity: " << section.capacity << "  | "  << std::endl;
}
//ID único, capacidade máxima e categoria

int* iniciarListaPecas(Section& section){
    section.listaPecas = new int[section.capacity];
    return section.listaPecas;
}

//void printLista(Section& section){
    //iniciarListaPecas(section);
    //for (int i = 0; i < section.capacity; i++) {
       // section.listaPecas[i] = 1;
    //}
    //for (int i = 0; i < section.capacity; i++) {
        //std::cout << section.listaPecas[i] << " ";
    //}
    //std::cout << std::endl;
//}