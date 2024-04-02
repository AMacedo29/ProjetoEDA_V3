#include <iostream>
#include "utils.h"
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function
#include "pecas.h"
#include "simulator.h" // para a listaDeChegadaSize
#include <unordered_set>

/**
 * Esta função inicializa a lista de chegada de peças com base nas categorias das seccoes disponiveis.
 * Ela gera aleatoriamente peças com informações como probabilidade de venda, preço, categoria, marca e número de série.
 * @param section Referência à struct section.
 * @param sectionsArray Ponteiro para o array de seccoes.
 * @return Um ponteiro para a lista de chegada de peças inicializada.
 */
Peca* iniciarListaChegada(Section& section, Section* sectionsArray) {
    Peca* listaChegada = new Peca[50];
    srand(time(nullptr));
    std::unordered_set<int> serialNumberUsado;
    for (int i = 0; i < 10; ++i) {
        int indiceRandomCat = rand() % section.tamanho;
        listaChegada[i].sellprob = calculateRandomNumber(5, 50);
        listaChegada[i].price = calculateRandomNumber(2, 180) * 5;
        listaChegada[i].category = sectionsArray[indiceRandomCat].category; // gera uma categoria aleatoria para a peca
        listaChegada[i].brand = getRandomMarca(); // gera uma marca aleatoria para a peca
        do {
            listaChegada[i].serialNumber = calculateRandomNumber(1000, 9999);; // Gera uma categoria aleatória
        } while (serialNumberUsado.count(listaChegada[i].serialNumber) > 0); // Verifica se a categoria já foi usada

        serialNumberUsado.insert(listaChegada[i].serialNumber);
    }
    listaDeChegadaSize = 10;
    return listaChegada;
}

/**
 * Esta função imprime a lista de chegada de peças.
 * @param listaChegada Ponteiro para a lista de chegada de peças.
 */
void printListaChegada(Peca* listaChegada){
    std::cout << "      **********************************" << std::endl;
    std::cout << "      ******** Lista de Chegada" << " ********" << std::endl;
    std::cout << "      **********************************" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "      " << listaChegada[i].category << "  |  " <<  listaChegada[i].brand
        << "  |  " <<  listaChegada[i].serialNumber<< "  |  "  <<  listaChegada[i].price << " $" <<std::endl;
    }
}
/*
void ordenarListaPorMarca(Peca* listaChegada) {
    for (int i = 0; i < listaDeChegadaSize - 1; ++i) {
        for (int j = 0; j < listaDeChegadaSize - i - 1; ++j) {
            if (listaChegada[j].brand > listaChegada[j + 1].brand && listaChegada[j].price > listaChegada[j + 1].price) {
                Peca temp = listaChegada[j];
                listaChegada[j] = listaChegada[j + 1];
                listaChegada[j + 1] = temp;
            }
        }
    }
}
*/

/**
 * Esta função ordena a lista de chegada de peças por preço, em ordem crescente.
 * @param listaChegada Ponteiro para a lista de chegada de peças.
 */
void ordenarListaPorPreco(Peca* listaChegada) {
    for (int i = 0; i < listaDeChegadaSize - 1; ++i) {
        for (int j = 0; j < listaDeChegadaSize - i - 1; ++j) {
            if (listaChegada[j].price > listaChegada[j + 1].price) {
                Peca temp = listaChegada[j];
                listaChegada[j] = listaChegada[j + 1];
                listaChegada[j + 1] = temp;
            }
        }
    }
}
