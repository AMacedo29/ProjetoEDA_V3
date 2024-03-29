#include <iostream>
#include "utils.h"
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function
#include "pecas.h"
#include "simulator.h" // para a listaDeChegadaSize

Peca* iniciarListaChegada(Section& section, Section* sectionsArray) {
    Peca* listaChegada = new Peca[50];
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
        int indiceRandomCat = rand() % section.tamanho;
        listaChegada[i].sellprob = calculateRandomNumber(5,50);
        listaChegada[i].serialNumber = calculateRandomNumber(1000,9999);
        listaChegada[i].price = calculateRandomNumber(2, 180) * 5;
        listaChegada[i].category = sectionsArray[indiceRandomCat].category; // gera uma categoria aleatoria para a peca
        listaChegada[i].brand = getRandomMarca(); // gera uma marca aleatoria para a peca
        listaDeChegadaSize = 10;
    }
    return listaChegada;
}

void printListaChegada(Peca* listaChegada){
    std::cout << "      **********************************" << std::endl;
    std::cout << "      ******** Lista de Chegada" << " ********" << std::endl;
    std::cout << "      **********************************" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "      " << listaChegada[i].category << "  |  " <<  listaChegada[i].brand
        << "  |  " <<  listaChegada[i].serialNumber<< "  |  "  <<  listaChegada[i].price << " $" <<std::endl;
    }
}

