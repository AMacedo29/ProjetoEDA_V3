#ifndef PROJETOEDA_SIMULATOR_H
#define PROJETOEDA_SIMULATOR_H
#include "sections.h"
#include "pecas.h"

void adicionarPeca(Peca* listaChegada, int& NextDayPecas, Section& section, Section* sectionsArray);

void mostrarPecas(Peca* listaChegada, int NextDayPecas, int dia);

extern int listaDeChegadaSize; // tive q usar extern pq a variavel está declarada no simulador.cpp

Peca* listaEsperaPeca(Peca* listaChegada, Section& section, Section* sectionsArray, int totalCapacity);

void printNewSection(Section& section, Section* sectionsArray);

void removerPecasAdicionadasListaChegada(Peca* listaChegada, Section& section);

void removerPecasComSerialNumberNegativo(Peca* listaChegada);

#endif //PROJETOEDA_SIMULATOR_H
