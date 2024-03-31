#include <string>
#include <iostream>
#include "pecas.h"
#include "sections.h"

//
//
// Ponto 3.1 - Venda Manual
void  SellManual(Peca* listaChegada, Section* sectionarray, Section& section){
    char sectionIDsell;
    std::string brandsell;
    bool flagsection = false;
    std::cout << "Escolheu a opcao 1 - Venda Manual" << std::endl;
    do {
        std::cout << "Digite o ID da seccao: " << std::endl;
        std::cin >> sectionIDsell;
        for (int i = 0; i < section.tamanho; ++i) {
            if (sectionIDsell == sectionarray[i].id) {
                flagsection = true;
            }
        }
        if (!flagsection) { // flagbrand == false
            std::cout << "ID da seccao invalida. Tente novamente." << std::endl;
        }else{
            std::cout << "Foi encontrado seccao!" << std::endl;
            break;
        }
    } while (true);
    bool flagbrand = false;
    do {
        std::cout << "Digite a marca do produto: " << std::endl;
        std::cin >> brandsell;
        for (int i = 0; i < 50; ++i) {
            if (listaChegada[i].brand == brandsell) {
                flagbrand = true;
                break;
            }
        }
        if (!flagbrand) {
            std::cout << "Marca de Produto invalida. Tente novamente." << std::endl;
        } else {
            std::cout << "Foi encontrado a marca!" << std::endl;
            break;
        }
    } while (true); // Alterado para verificar !flagbrand
}
void addSection();
