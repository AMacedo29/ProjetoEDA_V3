#include <iostream>
#include "simulator.h"
#include "utils.h"
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function
#include "pecas.h"
#include "sections.h"
#include <algorithm>


int listaDeChegadaSize = 0; // variavel global para guardar o tamanho da lista

/**
*  adiciona pecas a lista de chegada
* esta funcao adiciona pecas (aleatoriamente) a lista de chegada desde que haja espaço disponivel na lista
* apos adicionar as pecas sao removidas da lista de chegada as pecas adicionadas e as pecas com os serial numbers negativos
*
* @param listaChegada um ponteiro para o array de peças representando a lista de chegada.
* @param NextDayPecas uma referencia para o inteiro que mantém o indice do proximo espaco disponivel na lista de chegada.
* @param section A secao da qual as pecas sao retiradas.
* @param sectionsArray Um ponteiro para o array de secoes disponiveis.
*/
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
/**
 * esta funcao mostra a lista  chegada no dia anterior, incluindo informações como categoria, marca, número de série e preço
 *
 * @param listaChegada um ponteiro para o array de pecas representando a lista de chegada
 * @param NextDayPecas o numero de pecas presentes na lista de chegada do dia anterior
 * @param dia o numero do dia para o qual a lista de chegada esta sendo exibida
 */
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

/**
 * Esta função cria uma lista de espera de peças com base na lista de chegada de peças,
 * uma seccão específica e um array de seccões, dada a capacidade total das seçoes e o número a adicionar
 * de peças por dia.
 * @param listaChegada Ponteiro para a lista de chegada de peças.
 * @param section Referência à struct section.
 * @param sectionsArray Ponteiro para o array de seccoes.
 * @param totalCapacity Capacidade total das seccoes.
 * @param pecasPorDia Número de peças que podem ser adicionadas à lista de espera por dia.
 * @return Um ponteiro para a lista de chegada de peças.
 */
Peca* listaEsperaPeca(Peca* listaChegada, Section& section, Section* sectionsArray, int totalCapacity, int pecasPorDia) {
    section.listaEspera = new Peca[totalCapacity];
    int pecasAdicionadas = 0;
    for (int i = 0; i < pecasPorDia && pecasAdicionadas < totalCapacity; i++) {
        for (int j = 0; j < section.tamanho; j++) {
            if (sectionsArray[j].category == listaChegada[i].category) {
                section.listaEspera[pecasAdicionadas++] = listaChegada[i];
                sectionsArray[j].quantity = pecasAdicionadas;
                break;
            }
        }
    }
    return section.listaEspera;
}

/**
 * Esta função imprime informações sobre as seccoes disponiveis, incluindo os detalhes de cada uma
 * e as peças em espera para cada categoria.
 * @param section Referência à struct section.
 * @param sectionsArray Ponteiro para o array de seções.
 * @param totalCapacity Capacidade total das seções.
 */
void printNewSection(Section& section, Section* sectionsArray, int totalCapacity){
    std::cout << "          *********************************************" << std::endl;
    std::cout << "          *** Armazem EDA  |  Total Faturacao " << section.totalIncome << " $" << " ***" << std::endl;
    std::cout << "          *********************************************" << std::endl;
    for (int i = 0; i < section.tamanho; i++) {
        std::cout << " Seccao " << sectionsArray[i].id << "  | " << " Categoria: " << sectionsArray[i].category
                  << "  | " << " Capacidade: " << sectionsArray[i].capacity << "  | " << " Quantidade: " << sectionsArray[i].quantity << "  | "
                  << " Faturacao: " << "0" << std::endl;
        int count = 0;
        for (int j = 0; j < totalCapacity; j++) {
            if (section.listaEspera[j].category == sectionsArray[i].category) {
                std::cout << "      " << section.listaEspera[j].category << "  |  " << section.listaEspera[j].brand
                << "  |  " << section.listaEspera[j].serialNumber << "  |  "
                << section.listaEspera[j].price << " $" << std::endl;
                count++;
                if (count == 8)
                    break;
            }
        }
    }
}

/**
 * Esta função remove as peças que foram adicionadas à lista de espera da lista de chegada de peças.
 * Coloca as peças com o serialNumber negativo de modo a ter acesso às peças que foram adicionadas.
 * @param listaChegada Ponteiro para a lista de chegada de peças.
 * @param section Referência à struct section.
 */
void removerPecasAdicionadasListaChegada(Peca* listaChegada, Section& section) {
    for (int i = 0; i < listaDeChegadaSize; i++) {
        bool encontrouPecaAdicionada = false;
        for (int j = 0; j < 8; j++) {
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

/**
 * Esta função simula a venda de peças da lista de espera de uma seção.
 * As peças são vendidas com base em uma probabilidade de venda.
 * @param section Referência à struct section contendo a lista de espera e o número de série registrado.
 * @param totalCapacity Capacidade total da seção.
 */
void vendaPecas(Section& section, int totalCapacity){
    section.serialNumberReg = new int[totalCapacity];
    int probabilidade = calculateRandomNumber(0,100);
    for (int i = 0; i < totalCapacity; i++){
        if (section.listaEspera[i].sellprob < probabilidade){
            section.serialNumberReg[i] = section.listaEspera[i].serialNumber;
            section.totalIncome += section.listaEspera[i].price;
            section.listaEspera[i].serialNumber = -1;
        }
    }
    removerPecasVendidas(section, totalCapacity);
}

/**
 * Esta função remove as peças da lista de chegada que possuem número de série negativo (-1).
 * @param listaChegada Ponteiro para a lista de chegada de peças.
 */
void removerPecasComSerialNumberNegativo(Peca* listaChegada) {
    Peca* newEnd = std::remove_if(listaChegada, listaChegada + listaDeChegadaSize,
                                  [](const Peca& p) { return p.serialNumber == -1; });
    int numToRemove = listaDeChegadaSize - (newEnd - listaChegada);
    listaDeChegadaSize -= numToRemove;
}

/**
 * Esta função remove as peças vendidas da lista de espera de uma seccão.
 * As peças vendidas são aquelas com número de série igual a -1.
 * @param section Referência à struct section.
 * @param totalCapacity Capacidade total das seccoes.
 */
void removerPecasVendidas(Section& section, int totalCapacity) {
    Peca* newEnd = std::remove_if(section.listaEspera, section.listaEspera + totalCapacity,
                                  [](const Peca& p) { return p.serialNumber == -1; });
    int numToRemove = totalCapacity - (newEnd - section.listaEspera);
    totalCapacity -= numToRemove;
}



