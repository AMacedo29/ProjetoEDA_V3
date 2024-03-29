#include <iostream>
#include "sections.h"
#include "sales.h"
#include "utils.h"
#include "pecas.h"
#include "simulator.h"

Section* inicializeSections(Section& section){
    srand(time(nullptr));
    section.tamanho = calculateRandomNumber(7, 10);
    Section* sectionsArray = new Section[section.tamanho];
    for (int i = 0; i < section.tamanho ; ++i) {
        sectionsArray[i].id = static_cast<char>(i + 65);
        sectionsArray[i].capacity = calculateRandomNumber(3, 6);
        sectionsArray[i].category = getRandomCategoria(); // gera uma categoria aleatoria para a section
    }
    return sectionsArray;
}


void addPecaToSection(Peca* listaChegada,int listaDeChegadaSize, Section* sectionsArray, Section& section){
    for (int i = 0; i < section.tamanho; i++){
        for (int j = 0; j < listaDeChegadaSize; j++)
            if (sectionsArray[i].category == listaChegada[j].category){
                std::cout << "      " << listaChegada[j].category << "  |  " <<  listaChegada[j].brand
                          << "  |  " <<  listaChegada[j].serialNumber<< "  |  "  <<  listaChegada[j].price << " $" <<std::endl;
            }
    }
}


void printSection(Section& section, Section* sectionsArray){
    std::cout << "          *********************************************" << std::endl;
    std::cout << "          *** Armazem EDA  |  Total Faturacao " << getTotalSales() << " $" << " ***" << std::endl;
    std::cout << "          *********************************************" << std::endl;
    for (int i = 0; i < section.tamanho; ++i) {
        std::cout << " Seccao " << sectionsArray[i].id << "  | " << " Categoria: " << sectionsArray[i].category
                  << "  | " << " Capacidade: " << sectionsArray[i].capacity << "  | " << " Quantidade: " << sectionsArray[i].quantity << "  | "
                  << " Faturacao: " << "0" << std::endl;
    }
}

