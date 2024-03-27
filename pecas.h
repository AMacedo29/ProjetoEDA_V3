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

void adicionarPecas(Peca* listaChegada, int& NextDayPecas);

void adicionarPeca();

void mostrarPecas(Peca* listaChegada, int NextDayPecas, int dia);

#endif //PROJETOEDA_PECAS_H
