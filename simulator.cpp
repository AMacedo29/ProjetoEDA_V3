#include <iostream>
#include "simulator.h"
#include "utils.h"
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function
#include "pecas.h"
#include "sales.h"
#include "sections.h"
#include <algorithm>


int listaDeChegadaSize = 0; // variavel global para guardar o tamanho da lista

void adicionarPeca(Peca* listaChegada, int& NextDayPecas, Section& section, Section* sectionsArray) {
    if (NextDayPecas >= 50) {
        std::cout << "A lista de chegada esta cheia. Nao e possivel adicionar mais pecas." << std::endl;
        return;
    }
    srand(time(nullptr));
    for (int i = 0; i < 5; i++) {
        int indiceRandomCat = rand() % section.tamanho;
        listaChegada[NextDayPecas].sellprob = calculateRandomNumber(5, 50);
        listaChegada[NextDayPecas].serialNumber = calculateRandomNumber(1000, 9999);
        listaChegada[NextDayPecas].price = calculateRandomNumber(2, 180) * 5;
        listaChegada[NextDayPecas].category = sectionsArray[indiceRandomCat].category; // gera uma categoria aleatoria para a peca
        listaChegada[NextDayPecas].brand = getRandomMarca(); // gera uma marca aleatoria para a peca
        NextDayPecas++;
        if (listaDeChegadaSize < 50) {
            listaDeChegadaSize++;
        }
    }
    removerPecasAdicionadasListaChegada(listaChegada,section);//arranjar
    removerPecasComSerialNumberNegativo(listaChegada);
}

void mostrarPecas(Peca* listaChegada, int NextDayPecas, int dia) {
    std::cout << "*******************************************" << std::endl;
    std::cout << "******** Lista de Chegada do dia " << dia -1 << " ********" << std::endl;
    std::cout << "*******************************************" << std::endl;
    for (int i = 0; i < NextDayPecas; i++) {
        if (listaChegada[i].category != "" && listaChegada[i].brand != "" && listaChegada[i].serialNumber != -1 && listaChegada[i].price != -1) {
            std::cout << listaChegada[i].category << "  |  "
                      << listaChegada[i].brand << "  |  "
                      << listaChegada[i].serialNumber << "  |  "
                      << listaChegada[i].price << " $" << std::endl;
        }
    }
}


Peca* listaEsperaPeca(Peca* listaChegada, Section& section, Section* sectionsArray, int totalCapacity) {
    section.listaEspera = new Peca[totalCapacity];
    int pecasAdicionadas = 0;
    for (int i = 0; i < listaDeChegadaSize && pecasAdicionadas < totalCapacity; ++i) {
        for (int j = 0; j < section.tamanho; ++j) {
            if (sectionsArray[j].category == listaChegada[i].category) {
                section.listaEspera[pecasAdicionadas++] = listaChegada[i];
                break;
            }
            sectionsArray[j].quantity = pecasAdicionadas;
        }
    }
    return section.listaEspera;
}



void printNewSection(Section& section, Section* sectionsArray){
    std::cout << "          *********************************************" << std::endl;
    std::cout << "          *** Armazem EDA  |  Total Faturacao " << getTotalSales() << " $" << " ***" << std::endl;
    std::cout << "          *********************************************" << std::endl;
    for (int i = 0; i < section.tamanho; i++) {
        std::cout << " Seccao " << sectionsArray[i].id << "  | " << " Categoria: " << sectionsArray[i].category
                  << "  | " << " Capacidade: " << sectionsArray[i].capacity << "  | " << " Quantidade: " << sectionsArray[i].quantity << "  | "
                  << " Faturacao: " << "0" << std::endl;
        for (int j = 0; j < 8; j++) {
            if (section.listaEspera[j].category == sectionsArray[i].category) {
                std::cout << "      " << section.listaEspera[j].category << "  |  " <<  section.listaEspera[j].brand
                          << "  |  " <<  section.listaEspera[j].serialNumber<< "  |  "  <<  section.listaEspera[j].price << " $" <<std::endl;
            }
        }
    }
}

void removerPecasAdicionadasListaChegada(Peca* listaChegada, Section& section) {
    for (int i = 0; i < listaDeChegadaSize; ++i) {
        bool encontrouPecaAdicionada = false;
        for (int j = 0; j < 8; ++j) {
            if (listaChegada[i].serialNumber == section.listaEspera[j].serialNumber){
                encontrouPecaAdicionada = true;
                break;
            }
        }
        if (encontrouPecaAdicionada) {
            listaChegada[i].serialNumber = -1;
        }
    }
}

void removerPecasComSerialNumberNegativo(Peca* listaChegada) {
    Peca* newEnd = std::remove_if(listaChegada, listaChegada + listaDeChegadaSize,
                                  [](const Peca& p) { return p.serialNumber == -1; });
    int numToRemove = listaDeChegadaSize - (newEnd - listaChegada);
    listaDeChegadaSize -= numToRemove;
}