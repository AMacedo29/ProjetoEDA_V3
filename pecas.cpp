#include <iostream>
#include "utils.h"
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function
#include "pecas.h"

Peca* iniciarListaChegada() {
    Peca* listaChegada = new Peca[10];
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
        listaChegada[i].sellprob = calculateRandomNumber(5,50);
        listaChegada[i].serialNumber = calculateRandomNumber(1000,9999);
        listaChegada[i].price = calculateRandomNumber(2, 180) * 5;
        listaChegada[i].category = "PEC"; // mudar para receber do ficheiro categorias.txt
        listaChegada[i].supplier = "Tillers"; // mudar para receber do ficheiro marcas.txt
    }
    return listaChegada;
}

void printListaChegada(Peca* listaChegada){
    std::cout << "      **********************************" << std::endl;
    std::cout << "      ******** Lista de Chegada" << " ********" << std::endl;
    std::cout << "      **********************************" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "      " << listaChegada[i].category << "  |  " <<  listaChegada[i].supplier
        << "  |  " <<  listaChegada[i].serialNumber<< "  |  "  <<  listaChegada[i].price << " $" <<std::endl;
    }
}

