#ifndef PROJETOEDA_SIMULATOR_H
#define PROJETOEDA_SIMULATOR_H
#include "sections.h"

void adicionarPeca(Peca* listaChegada, int& NextDayPecas, Section& section, Section* sectionsArray);

void mostrarPecas(Peca* listaChegada, int NextDayPecas, int dia);

extern int listaDeChegadaSize; // tive q usar extern pq a variavel está declarada no simulador.cpp

#endif //PROJETOEDA_SIMULATOR_H
