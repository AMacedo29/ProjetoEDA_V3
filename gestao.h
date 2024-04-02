//
// Created by KAMAXO on 29/03/2024.
//

#ifndef PROJETOEDA_GESTAO_H
#define PROJETOEDA_GESTAO_H

// Funclão 3.1 - Venda Manual
void SellManual(Peca* listaChegada, Section* sectionarray, Section& section);

//Função 3.2 - Promoção
void promocao(Section& section, Section* sectionsArray, int totalCapacity);

// Função 3.3 - Muda Categoria
void mudaCategoria(Section* sectionarray, Section& section);

// Função 3.4 - Adicionar Secção
void addSection(Section* sectionarray, Section& section);

// Funcção 3.5 - Guardar dados do armazem e lista
void gravarlistachegada(Peca* listaChegada);
void gravararmazem(Section* sectionsArray, Section& section);
void gravartotalfacturamente(Section& section);

#endif //PROJETOEDA_GESTAO_H
