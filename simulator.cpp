#include <iostream>
#include "simulator.h"
#include "utils.h"
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function
#include "pecas.h"
#include "sections.h"


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
}

void mostrarPecas(Peca* listaChegada, int NextDayPecas, int dia) {
    std::cout << "*******************************************" << std::endl;
    std::cout << "******** Lista de Chegada do dia " << dia -1 << " ********" << std::endl;
    std::cout << "*******************************************" << std::endl;
    for (int i = 0; i < NextDayPecas; i++) {
        std::cout << listaChegada[i].category << "  |  "
                  << listaChegada[i].brand << "  |  "
                  << listaChegada[i].serialNumber << "  |  "
                  << listaChegada[i].price << " $" << std::endl;
    }
}

void inserirPecasArmazem(Peca* listaChegada, Section* sectionsArray, Section& section){ //ainda não está certo
    addPecaToSection(listaChegada, sectionsArray, section);

    for (int i = 0; i < section.tamanho; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (sectionsArray[i].category == listaChegada[j].category) {
                listaChegada[j] = listaChegada[listaDeChegadaSize - 1];
                --listaDeChegadaSize;
                break;
            }
        }
    }
    //talvez usar a listaPecas do section para retornar um array com isto e so depois iterar

}

void addPecaToSection(Peca* listaChegada, Section* sectionsArray, Section& section){//ainda não está certo
    for (int i = 0; i < section.tamanho; i++){
        for (int j = 0; j < 8; j++)
            if (sectionsArray[i].category == listaChegada[j].category){
                std::cout << "      " << listaChegada[j].category << "  |  " <<  listaChegada[j].brand
                          << "  |  " <<  listaChegada[j].serialNumber<< "  |  "  <<  listaChegada[j].price << " $" <<std::endl;
            }
    }
}