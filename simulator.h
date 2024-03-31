#ifndef PROJETOEDA_SIMULATOR_H
#define PROJETOEDA_SIMULATOR_H
#include "sections.h"
#include "pecas.h"

void adicionarPeca(Peca* listaChegada, int& NextDayPecas, Section& section, Section* sectionsArray);

void mostrarPecas(Peca* listaChegada, int NextDayPecas, int dia);

extern int listaDeChegadaSize; // tive q usar extern pq a variavel está declarada no simulador.cpp

void addPecaToSection(Peca* listaChegada, Section* sectionsArray, Section& section);

void inserirPecasArmazem(Peca* listaChegada, Section* sectionsArray, Section& section);

#endif //PROJETOEDA_SIMULATOR_H
