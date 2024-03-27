#include <iostream>
#include "utils.h"
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function
#include "pecas.h"


Peca* iniciarListaChegada() {
    Peca* listaChegada = new Peca[30];
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
        listaChegada[i].sellprob = calculateRandomNumber(5,50);
        listaChegada[i].serialNumber = calculateRandomNumber(1000,9999);
        listaChegada[i].price = calculateRandomNumber(2, 180) * 5;
        listaChegada[i].category = getRandomCategoria(); // gera uma categoria aleatoria para a peca
        listaChegada[i].brand = getRandomMarca(); // gera uma marca aleatoria para a peca
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

void adicionarPeca(Peca* listaChegada, int& NextDayPecas) {
    if (NextDayPecas >= 30) {
        std::cout << "A lista de chegada esta cheia. Nao e possivel adicionar mais pecas." << std::endl;
        return;
    }
    listaChegada[NextDayPecas].sellprob = calculateRandomNumber(5,50);
    listaChegada[NextDayPecas].serialNumber = calculateRandomNumber(1000,9999);
    listaChegada[NextDayPecas].price = calculateRandomNumber(2, 180) * 5;
    listaChegada[NextDayPecas].category = getRandomCategoria(); // gera uma categoria aleatoria para a peca
    listaChegada[NextDayPecas].brand = getRandomMarca(); // gera uma marca aleatoria para a peca
    NextDayPecas++;
}

void adicionarPecas(Peca* listaChegada, int& NextDayPecas) {
    for (int i = 0; i < 5; i++) {
        adicionarPeca(listaChegada, NextDayPecas);
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