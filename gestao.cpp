#include <string>
#include <iostream>
#include "pecas.h"
#include "sections.h"

//
//
// Ponto 3.1 - Venda Manual
// Funções Funcionais
bool validateSectionID(char id, Section* sectionarray, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        if (id == sectionarray[i].id) {
            return true;
        }
    }
    return false;
}

bool validateProductBrand(std::string marca, Peca* listaChegada, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        if (marca == listaChegada[i].brand) {
            return true;
        }
    }
    return false;
}

bool validateCategory(std::string categoria, Section* sectionarray, int tamanho){
    for (int i = 0; i < tamanho; ++i) {
        if(categoria == sectionarray[i].category){
            return true;
        }

    }
    return false;
}

void SellManual(Peca* listaChegada, Section* sectionarray, Section& section){
    char sectionIDsell;
    std::string brandsell;

    std::cout << "Escolheu a opcao 1 - Venda Manual" << std::endl;
    // Loop para validar o ID da seção
    do {
        std::cout << "Digite o ID da seccao: " << std::endl;
        std::cin >> sectionIDsell;
        if (!validateSectionID(sectionIDsell, sectionarray, section.tamanho)) {
            std::cout << "ID da seccao invalida. Tente novamente." << std::endl;
        } else {
            std::cout << "Foi encontrado seccao!" << std::endl;
            break;
        }
    } while (true);

    // Loop para validar a marca do produto
    do {
        std::cout << "Digite a marca do produto: " << std::endl;
        std::cin >> brandsell;
        if (!validateProductBrand(brandsell, listaChegada, 50)) {
            std::cout << "Marca de Produto invalida. Tente novamente." << std::endl;
        } else {
            std::cout << "Foi encontrado a marca!" << std::endl;
            break;
        }
    } while (true);
}

void mudaCategoria(Section* sectionarray, Section& section){
    std::string mudacategoria;
    char sectionchange;
    do {
        std::cout << "Digite a seccao" << std::endl;
        std::cin >> sectionchange;
        if(!validateSectionID(sectionchange, sectionarray, section.tamanho)){
            std::cout << "Seccao invalida. Tente novamente." << std::endl;
        } else {
            std::cout << "Foi encontrado Categoria!" << std::endl;
            break;
        }
    } while(true);
        std::cout << "Digite a categoria que deseja alterar" << std::endl;
        std::cin >> mudacategoria;
        for(int i = 0; i < section.tamanho; ++i){
            if(sectionchange == sectionarray[i].id){
                sectionarray[i].category = mudacategoria;
                std::cout << "Categoria alterada com secesso." << std::endl;
                break;
            }
        }
}
