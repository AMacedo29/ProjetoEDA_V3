#ifndef PROJETOEDA_SECTIONS_H
#define PROJETOEDA_SECTIONS_H
#include "pecas.h"

class Peca;

struct Section{
    char id;
    int capacity;
    std::string category;
    int quantity;
    int totalIncome;
    int* serialNumberReg;
    Peca *listaEspera;
    int tamanho;

};


Section* inicializeSections(Section& section);

void printSection(Section& section, Section* sectionsArray);

int sectionsCapacity(Section& section, Section* sectionsArray);


#endif //PROJETOEDA_SECTIONS_H
