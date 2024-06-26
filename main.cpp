#include <iostream>
#include <limits>
#include <ctime>
#include "pecas.h"
#include "sections.h"
#include "utils.h"
#include "simulator.h"
#include "gestao.h"

int dia=1;
int NextDayPecas = 10;
/**
 * Função para com menu para pedir ao utizador de que forma quer ordenar a lista de chegada
 * @param listaChegada - Ponteiro para a lista de  chegada
 * @return - Retorna 0
 * Explicação: Pede ao utizador valores 1 ou 2
 * 1 - Faz ordenação da lista pela Marca;
 * 2 - Faz ordenação da lista por preco;
 * Ao inserir 0 sai do menu;
 */
int sub_menu(Peca* listaChegada){
    bool sair = false;
    char optionsub;
    do {
        std::cout << "***** Imprimir Lista *****" << std::endl;
        std::cout << "1 - Ordenar lista por Marca " << std::endl;
        std::cout << "2 - Ordenar lista por Preco " << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Escolha a sua option: " << std::endl;
        std::cin >> optionsub;
        std::cout << std::endl;
        switch (optionsub) {
            case '1':
                std::cout << "Lista Ordenada por Marca" << std::endl;
                //ordenarListaPorMarca(listaChegada);
                printListaChegada(listaChegada);
                break;
            case '2':
                std::cout << "Lista Ordenada por Preco" << std::endl;
                ordenarListaPorPreco(listaChegada);
                printListaChegada(listaChegada);
                break;
            case '0':
                std::cout << "Escolheu a opcao Sair. Adeus!" << std::endl;
                sair = true;
                break;
            default:
                std::cout << "Opcao Invalida" << std::endl;
        }
    } while (!sair);
    return 0;
}

/**
 * Função do menu para a gestão
 * @param sectionsArray - Ponteiro para a secção
 * @param listaChegada - Ponteiro para lista de chegada
 * @param section - Referncias para Secções
 * Explicação:
 * Este menu serve para a gestão do armazem, no qual, o utilizador tem a possibilidade, vender pecas manualmente,
 * adicionar promoca, mudar a categoria, adicionar secção ao armazem
 * gravar os dados em ficheiro e imprimir armzem;
 * Ao inserir 0 sai do menu;
 * Os parametros são usados para funções
 */
void menu_manager(Section* sectionsArray, Peca* listaChegada, Section& section) {
    bool sair = false;
    char option;
    int totalCapacity = sectionsCapacity(section, sectionsArray);
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
                //Venda  3.1
                SellManual(listaChegada, sectionsArray, section); //Rever
                /*std::cout << "Digite o ID da seccao: " << std::endl;
                std::cout << "O ID da seccao que tentou inserir e invalido tente outro ID : " << std::endl;
                std::cout << "Digite a marca do produto: " << std::endl;
                std::cout << "A marca que tentou inserir e invalida tente outra marca: " << std::endl;
                std::cout << "Venda efetuada com sucesso!" << std::endl;*/
                break;
            case '2':
                promocao(section,sectionsArray,totalCapacity);
                break;
            case '3':
                mudaCategoria(sectionsArray, section);
                /*
                std::cout << "Escolheu a opcao 3 - Alterar categoria " << std::endl;
                std::cout << "Digite o ID da seccao que deseja mudar: " << std::endl;
                std::cout << "O ID da seccao que tentou inserir e invalido tente outro ID : " << std::endl;
                std::cout << "Digite a nova categoria para a seccao: " << std::endl;
                std::cout << "Categoria invalida. Digite outra caregoria: " << std::endl;*/
                break;
            case '4':
                //addSection(sectionsArray, section);
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
                gravartotalfacturamente(section);
                gravarlistachegada(listaChegada);
                gravararmazem(sectionsArray, section);
                //std::cout << "Escolheu a opcao 5 - Gravar Armazem " << std::endl;
                break;
            case '6':
                std::cout << "Escolheu a opcao 6 - Carregar Armazem " << std::endl;
                break;
            case '7':
                std::cout << "Escolheu a opcao 7 - Imprimir Armazem " << std::endl;
                printNewSection(section, sectionsArray, totalCapacity);
                adicionarPeca(listaChegada, NextDayPecas, section, sectionsArray);
                ordenarListaPorPreco(listaChegada);
                //ordenarListaPorMarca(listaChegada);
                vendaPecas(section,totalCapacity);
                mostrarPecas(listaChegada, NextDayPecas, dia);
                std::cout << listaDeChegadaSize << std::endl;
                std::cout << section.totalIncome << std::endl;
                sub_menu(listaChegada);
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
    ordenarListaPorPreco(listaChegada);
    //ordenarListaPorMarca(listaChegada);
    printListaChegada(listaChegada);
    std::cout << section.totalIncome << std::endl;
    int totalCapacity = sectionsCapacity(section, sectionsArray);
    section.listaEspera = listaEsperaPeca(listaChegada, section, sectionsArray, totalCapacity,8);
    bool sair = false;
    char option0;
    //int dia=1;
    //int NextDayPecas = 10;

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
                printNewSection(section, sectionsArray, totalCapacity);
                adicionarPeca(listaChegada, NextDayPecas, section, sectionsArray);
                ordenarListaPorPreco(listaChegada);
                //ordenarListaPorMarca(listaChegada);
                vendaPecas(section,totalCapacity);
                mostrarPecas(listaChegada, NextDayPecas, dia);
                std::cout << listaDeChegadaSize << std::endl;
                std::cout << section.totalIncome << std::endl;
                break;
            case 'g':
                menu_manager(sectionsArray, listaChegada, section);
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