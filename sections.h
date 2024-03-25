#ifndef PROJETOEDA_SECTIONS_H
#define PROJETOEDA_SECTIONS_H

struct Section{
    char id;
    int capacity;
    std::string category; // se isto ficar na linha 6 da erro
    int quantity;
    Section *sections;
    int totalIncome;
    int serialNumberReg;
    int *listaPecas;
};

void printSection(Section& section);

#endif //PROJETOEDA_SECTIONS_H
