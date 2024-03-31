#include <iostream>
#include <limits>
#include <ctime>
#include "pecas.h"
#include "sections.h"
#include "utils.h"
#include "simulator.h"
#include "gestao.h"

void menu_manager(Section* sectionsArray, Peca* listaChegada) {
    bool sair = false;
    char option;
    Section section;



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
                std::cout << "Escolheu a opcao 1 - Venda Manual" << std::endl;
                //SellManual(listaChegada, *sectionsArray, 50); //Rever
                /*std::cout << "Digite o ID da seccao: " << std::endl;
                std::cout << "O ID da seccao que tentou inserir e invalido tente outro ID : " << std::endl;
                std::cout << "Digite a marca do produto: " << std::endl;
                std::cout << "A marca que tentou inserir e invalida tente outra marca: " << std::endl;
                std::cout << "Venda efetuada com sucesso!" << std::endl;*/
                break;
            case '2':
                std::cout << "Escolheu a opcao 2 - Promocao" << std::endl;
                std::cout << "Duracao da promoção (em dias): " << std::endl;
                std::cout << "Percentagem de desconto: " << std::endl;
                std::cout << "Digite o ID da seccao que ira ter o desconto: " << std::endl;
                std::cout << "O ID da seccao que tentou inserir e invalido tente outro ID : " << std::endl;
                break;
            case '3':
                std::cout << "Escolheu a opcao 3 - Alterar categoria " << std::endl;
                std::cout << "Digite o ID da seccao que deseja mudar: " << std::endl;
                std::cout << "O ID da seccao que tentou inserir e invalido tente outro ID : " << std::endl;
                std::cout << "Digite a nova categoria para a seccao: " << std::endl;
                std::cout << "Categoria invalida. Digite outra caregoria: " << std::endl;
                break;
            case '4':
                /*
                std::cout << "Escolheu a opcao 4 - Adicionar seccao  " << std::endl;
                std::cout << "Digite o ID da seccao:" << std::endl;
                std::cout << "O ID da seccao que tentou inserir ja existe tente outro ID : " << std::endl;
                std::cout << "Escolha a capacidade maxima da seccao (min:3 | max:6): " << std::endl;
                std::cout << "Capacidade invalida escolha entre estes valores (min:3 | max:6): " << std::endl;
                std::cout << "Escolha a categoria para a seccao" << std::endl;
                 */
                break;
            case '5':
                std::cout << "Escolheu a opcao 5 - Gravar Armazem " << std::endl;
                break;
            case '6':
                std::cout << "Escolheu a opcao 6 - Carregar Armazem " << std::endl;
                break;
            case '7':
                std::cout << "Escolheu a opcao 7 - Imprimir Armazem " << std::endl;
                break;
            case '0':
                std::cout << "Escolheu a opcao Sair. Adeus!" << std::endl;
                sair = true;
                break;
            default:
                std::cout << "Opcao Invalida" << std::endl;

        }
    }while (!sair);

}

int main() {
    Section section;
    Section* sectionsArray = inicializeSections(section);
    printSection(section,sectionsArray);
    Peca* listaChegada = iniciarListaChegada( section, sectionsArray);
    ordenarListaPorMarca(listaChegada);
    printListaChegada(listaChegada);
    bool sair = false;
    char option0;
    int dia=1;
    int NextDayPecas = 10;

    do{
        std::cout << std::endl;
        std::cout << "Dia (s)eguinte *********** (g)estao" << std::endl;
        std::cout << "Seleccione a sua opcao:" << std::endl;
        std::cin >> option0;
        // Limpa o buffer de entrada
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(option0){
            case 's':
                std::cout << "Dia: "  << dia << std::endl;
                dia++;
                adicionarPeca(listaChegada, NextDayPecas, section, sectionsArray);
                ordenarListaPorMarca(listaChegada);
                printSection(section,sectionsArray);
                inserirPecasArmazem(listaChegada,sectionsArray, section);
                mostrarPecas(listaChegada, NextDayPecas, dia);
                std::cout << listaDeChegadaSize << std::endl;
                break;
            case 'g':
                menu_manager(sectionsArray, listaChegada);
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