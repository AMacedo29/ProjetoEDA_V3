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
//Incompleto
void SellManual(Peca* listaChegada, Section* sectionarray, Section& section){
    char sectionIDsell;
    std::string brandsell;

    std::cout << "Escolheu a opcao 1 - Venda Manual" << std::endl;
    // Loop para validar o ID da seção
    do {
        std::cout << "Digite o ID da seccao: " << std::endl;
        std::cin >> sectionIDsell;
        if (!validateSectionID(sectionIDsell, sectionarray, section.tamanho)) { //validateSectionID(sectionIDsell, sectionarray, section.tamanho) == false
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
//Incompleto
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

void addSection(Section* sectionarray, Section& section){
    char sectionID;
    int sectionCapacity;
    std::string sectionCategory;



    do {
        std::cout << "Digite o ID da seccao: " << std::endl;
        std::cin >> sectionID;
        if (!validateSectionID(sectionID, sectionarray, section.tamanho)) { //validateSectionID(sectionIDsell, sectionarray, section.tamanho) == false
            std::cout << "ID da seccao invalida. Tente novamente." << std::endl;
        } else {
            std::cout << "Foi encontrado seccao!" << std::endl;
            break;
        }
    } while (true);

    do {
        std::cout << "Digite a capacidade da seccao (valores entre 3 e 6): " << std::endl;
        std::cin >> sectionCapacity;
        if (sectionCapacity >= 3 && sectionCapacity <= 6 ) { //validateSectionID(sectionIDsell, sectionarray, section.tamanho) == false
            std::cout << "Capacidade Valida" << std::endl;
            break;
        } else {
            std::cout << "Capacidade invalida. Tente novamente." << std::endl;
        }
    } while (!(sectionCapacity >= 3 && sectionCapacity <= 6 ));

    std::cout << "Digite a Categoria: " << std::endl;
    std::cin >> sectionCategory;
    Section novasecao;


}
