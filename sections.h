#ifndef PROJETOEDA_SECTIONS_H
#define PROJETOEDA_SECTIONS_H

struct Section{
    char id;
    //char category[100]; // como isto n está a receber nada o print está ♥ ♣ ♦ ♠
    int capacity;
    std::string category; // se isto ficar na linha 6 da erro
    int totalIncome;
    int serialNumberReg;
    int *listaPecas;
};

void printSection(Section& section);

#endif //PROJETOEDA_SECTIONS_H
