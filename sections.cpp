#include <iostream>
#include "sections.h"
#include "utils.h"
#include "pecas.h"
#include "simulator.h"
#include <unordered_set>

/**
 * Esta função inicializa as seções do armazém.
 * Cada seccão recebe um id, uma capacidade e uma categoria única.
 * @param section Referência à struct section.
 * @return Um ponteiro para um array de seccões inicializado.
 */
Section* inicializeSections(Section& section){
    srand(time(nullptr));
    section.tamanho = calculateRandomNumber(7, 10);
    std::unordered_set<std::string> categoriasUsadas;
    Section* sectionsArray = new Section[section.tamanho];
    for (int i = 0; i < section.tamanho ; ++i) {
        sectionsArray[i].id = static_cast<char>(i + 65);
        sectionsArray[i].capacity = calculateRandomNumber(3, 6);
        do {
            sectionsArray[i].category = getRandomCategoria(); // Gera uma categoria aleatória
        } while (categoriasUsadas.count(sectionsArray[i].category) > 0); // Verifica se a categoria já foi usada

        categoriasUsadas.insert(sectionsArray[i].category);
    }
    return sectionsArray;
}

/**
 * Esta função imprime informações sobre as seccões do armazém, incluindo o id,
 * a categoria, a capacidade, a quantidade e a faturação total de cada seção.
 * @param section Referência à struct section.
 * @param sectionsArray Ponteiro para o array de seccões do armazém.
 */
void printSection(Section& section, Section* sectionsArray){
    std::cout << "          *********************************************" << std::endl;
    std::cout << "          *** Armazem EDA  |  Total Faturacao " << section.totalIncome << " $" << " ***" << std::endl;
    std::cout << "          *********************************************" << std::endl;
    for (int i = 0; i < section.tamanho; ++i) {
        std::cout << " Seccao " << sectionsArray[i].id << "  | " << " Categoria: " << sectionsArray[i].category
                  << "  | " << " Capacidade: " << sectionsArray[i].capacity << "  | " << " Quantidade: " << sectionsArray[i].quantity << "  | "
                  << " Faturacao: " << sectionsArray[i].totalIncome << std::endl;
    }
}

/**
 * Esta função calcula a capacidade total de todas as seccões do armazém.
 * @param section Referência à struct section.
 * @param sectionsArray Ponteiro para o array de seções do armazém.
 * @return A capacidade total de todas as seções do armazém.
 */
int sectionsCapacity(Section& section, Section* sectionsArray){
    int totalCapacity = 0;
    for (int i = 0; i < section.tamanho; i++){
        totalCapacity += sectionsArray[i].capacity;
    }
    return totalCapacity;
}

