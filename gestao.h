//
// Created by KAMAXO on 29/03/2024.
//

#ifndef PROJETOEDA_GESTAO_H
#define PROJETOEDA_GESTAO_H



void SellManual(Peca* listaChegada, Section* sectionarray, Section& section);

void addSection(Section* sectionarray, Section& section);

void mudaCategoria(Section* sectionarray, Section& section);

void promocao(Section& section, Section* sectionsArray, int totalCapacity);

#endif //PROJETOEDA_GESTAO_H
