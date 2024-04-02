#ifndef PROJETOEDA_PECAS_H
#define PROJETOEDA_PECAS_H
#include "sections.h"


class Section; // sem isto o iniciarListaChegada da erro

struct Peca {
    std::string brand;
    std::string category;
    int sellprob;
    int serialNumber;
    int price;
};

Peca* iniciarListaChegada(Section& section, Section* sectionsArray);

void printListaChegada(Peca* listaChegada);

//void ordenarListaPorMarca(Peca* listaChegada);

void ordenarListaPorPreco(Peca* listaChegada);


#endif //PROJETOEDA_PECAS_H
