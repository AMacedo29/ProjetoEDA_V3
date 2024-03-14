#include <iostream> // For the std::cout and std::endl functions
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
        listaChegada[i].category = "12";
        listaChegada[i].supplier = "Ferrari";
    }

    return listaChegada;
}

void printListaChegada(Peca* listaChegada){
    for (int i = 0; i < 10; ++i) {
        std::cout << "Peca " << i + 1 << ":" << std::endl;
        std::cout << "   Sell Probability: " << listaChegada[i].sellprob << std::endl;
        std::cout << "   Serial Number: " << listaChegada[i].serialNumber << std::endl;
        std::cout << "   Price: " << listaChegada[i].price << std::endl;
        std::cout << "   Category: " << listaChegada[i].category << std::endl;
        std::cout << "   Supplier: " << listaChegada[i].supplier << std::endl;
    }
}

//int pecasPrice() {
    // Initialize random seed
    //srand(time(0));

    //for (int i = 0; i < 10; ++i) { // Loop que imprime 10 preços diferentes

        // Generate a number between 2 and 180 and multiply it by 5 ex: 2*5 = 10 and 180*5 = 900
        //int precoPecas = calculateRandomNumber(2, 180) * 5;
        // We need to switch the i+1 to the peca name
        //std::cout << "The random price of item " << i+1 << " is: " << precoPecas << " euros" << std::endl;
    //}

    //return 0;
//}
