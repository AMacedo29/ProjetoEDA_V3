#include <string>
#include <iostream>
#include "pecas.h"
#include "sections.h"

//
//
// Ponto 3.1 - Venda Manual
void SellManual(Peca* listaChegada, Section& section){
    char sectionIDsell;
    std::string brandsell;
    std::cout << "Escolheu a opcao 1 - Venda Manual" << std::endl;
    //Inserção de id da secção e validação do mesmo
    //ALTERAR
    do {
        std::cout << "Digite o ID da seccao: " << std::endl;
        std::cin >> sectionIDsell;
        if (sectionIDsell != section.id) {
            std::cout << "ID da seccao invalida. Tente novamente." << std::endl;
        }
    } while (sectionIDsell != section.id);

    //Inserção da marca do produto e validação do mesmo
    //ALTERAR
    do {
        std::cout << "Digite a marca do produto: ";
        std::cin >> brandsell;
        if (brandsell != listaChegada->brand) {
            std::cout << "Marca do produto invalida. Tente novamente." << std::endl;
        }
    } while (brandsell != listaChegada->brand);
}

