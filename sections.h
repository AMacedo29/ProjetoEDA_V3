#ifndef PROJETOEDA_SECTIONS_H
#define PROJETOEDA_SECTIONS_H

struct Section{
    char id;
    int capacity;
    int totalIncome;
    int serialNumberReg;
    int *listaPecas;
};

void printSection(Section& section);

//int* iniciarListaPecas(Section& section);

//void printLista(Section& section);
#endif //PROJETOEDA_SECTIONS_H
