#ifndef PROJETOEDA_PECAS_H
#define PROJETOEDA_PECAS_H

int pecasPrice();

struct Peca {
    char supplier[100]; // Its 100 to not overflow
    char category[100];
    int sellprob;
    int serialNumber;
    int price;
};

#endif //PROJETOEDA_PECAS_H
