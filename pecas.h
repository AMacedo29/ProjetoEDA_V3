#ifndef PROJETOEDA_PECAS_H
#define PROJETOEDA_PECAS_H

struct Peca {
    std::string brand;
    std::string category;
    int sellprob;
    int serialNumber;
    int price;
};

Peca* iniciarListaChegada();

void printListaChegada(Peca* listaChegada);


#endif //PROJETOEDA_PECAS_H
