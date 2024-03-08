#include <iostream>
#include "initialization.h"


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
                std::cout << "funciona" << std::endl;
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
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
    initialize_wharehouse();
    bool sair = false;
    char option0;
    int dia=1;

    do{
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

