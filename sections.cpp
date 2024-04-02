#include <iostream>
#include "sections.h"
#include "utils.h"
#include "pecas.h"
#include "simulator.h"
#include <unordered_set>

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

int sectionsCapacity(Section& section, Section* sectionsArray){
    int totalCapacity = 0;
    for (int i = 0; i < section.tamanho; i++){
        totalCapacity += sectionsArray[i].capacity;
    }
    return totalCapacity;
}

