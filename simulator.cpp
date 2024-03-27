#include <iostream>
#include "simulator.h"
#include "utils.h"
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function
#include "pecas.h"
#include "sections.h"

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