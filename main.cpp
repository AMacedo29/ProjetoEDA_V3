#include <iostream>
#include "pecas.h"
#include "sections.h"
#include "utils.h"

int menu_manager() {
    bool sair = false;
    char option;

    do {
        std::cout << "***** Bem Vindo Gestor *****" << std::endl;
        std::cout << "1 - Venda Manual " << std::endl;
        std::cout << "2 - Promocao " << std::endl;
        std::cout << "3 - Alterar categoria " << std::endl;
        std::cout << "4 - Adicionar seccao " << std::endl;
        std::cout << "5 - Gravar Armazem " << std::endl;
        std::cout << "6 - Carregar Armazem " << std::endl;
        std::cout << "7 - Imprimir Armazem " << std::endl;
        std::cout << "0 - Sair "<< std::endl;
        std::cout << "Escolha a sua option: " << std::endl;
        std::cin >> option;
        std::cout << std::endl;

        switch (option) {
            case '1':
                std::cout << "opcao 1 " << std::endl;
                break;
            case '2':
                std::cout << "opcao 2 " << std::endl;
                break;
            case '3':
                std::cout << "opcao 3 " << std::endl;
                break;
            case '4':
                std::cout << "opcao 4 " << std::endl;
                break;
            case '5':
                std::cout << "opcao 5 " << std::endl;
                break;
            case '6':
                std::cout << "opcao 6 " << std::endl;
                break;
            case '7':
                std::cout << "opcao 7 " << std::endl;
                break;
            case '0':
                std::cout << "Escolheu a opcao Sair. Adeus!" << std::endl;
                sair = true;
                break;
            default:
                std::cout << "Opcao Invalida" << std::endl;

        }
    }while (!sair);
    return 0;
}

int main() {
    Section section;
    Section* sectionsArray = inicializeSections(section);
    printSection(section,sectionsArray);
    Peca* listaChegada = iniciarListaChegada();
    printListaChegada(listaChegada);
    bool sair = false;
    char option0;
    int dia=1;

    do{
        std::cout << std::endl;
        std::cout << "Dia (s)eguinte *********** (g)estao" << std::endl;
        std::cout << "Seleccione a sua opcao:" << std::endl;
        std::cin >> option0;
        switch(option0){
            case 's':
                std::cout << "Dia: "  << dia << std::endl;
                dia++;
                break;
            case 'g':
                menu_manager();
                break;
            case '0':
                std::cout << "Escolheu a opcao Sair. Adeus!" << std::endl;
                sair = true;
                break;
            default:
                std::cout << "Opcao Invalida" << std::endl;
        }
    }while (!sair);
    return 0;

}

