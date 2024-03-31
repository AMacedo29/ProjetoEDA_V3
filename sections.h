#ifndef PROJETOEDA_SECTIONS_H
#define PROJETOEDA_SECTIONS_H
#include "pecas.h"

struct Section{
    char id;
    int capacity;
    std::string category;
    int quantity;
    int totalIncome;
    int serialNumberReg;
    int *listaPecas;
    int tamanho;

};


Section* inicializeSections(Section& section);

void printSection(Section& section, Section* sectionsArray);


#endif //PROJETOEDA_SECTIONS_H
