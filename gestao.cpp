#include <string>
#include <iostream>
#include <fstream>
#include "pecas.h"
#include "sections.h"

//
//
// Ponto 3.1 - Venda Manual
// Funções
/**
 * Função para validar o ID da secção.
 *
 * @param id - Recebe o ID da seção a ser validado.
 * @param sectionarray - Ponteiro para o array de seções.
 * @param tamanho - Tamanho do array de seções.
 * @return Retorna true se o ID da seção for encontrado no array, caso contrário, retorna false.
 * Explicação:
 * Percorre o array de secções
 * Verifica se o ID fornecido corresponde ao ID da seção atual no índice atual do loop
 * Se houver uma correspondência retorna true, senão termina o loop e retorna false;
 */
bool validateSectionID(char id, Section* sectionarray, int tamanho) { // provavelmente queres Section* sectionsArray
    for (int i = 0; i < tamanho; ++i) {
        if (id == sectionarray[i].id) {
            return true;
        }
    }
    return false;
}

/**
 * Função para validar a marca do produtos
 * @param marca - Recebe marca do produto a ser valida.
 * @param listaChegada - Ponteiro para o array de produtos.
 * @param tamanho - Tamanho do array de produto(tamanho = 50, valor fixo);
 * @return - Retorna true se a marca do produto for encontrada no array, caso contrário, retorna false.
 * Explicação:
 * Percorre o array dos produtos
 * Verifica se a marca fornecida corresponde à marca do produto atual no índice atual do loop
 * Se houver uma correspondência retorna true, senão termina o loop e retorna false;
 */
bool validateProductBrand(std::string marca, Peca* listaChegada, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        if (marca == listaChegada[i].brand) {
            return true;
        }
    }
    return false;
}

/*
bool validateCategory(std::string categoria, Section* sectionarray, int tamanho){
    for (int i = 0; i < tamanho; ++i) {
        if(categoria == sectionarray[i].category){
            return true;
        }
    }
    return false;
}
*/
/**
 * Função para realizar uma venda manual de um produto
 * @param listaChegada - Ponteiro para lista de peças
 * @param sectionarray - Ponteiro para o array de secções
 * @param section - Referencias para a secção
 * Explicação:
 * Pede ao utlizador a secção e a marca do produto, usa as funções validateSectionID para verificar se existe a secção
 * e validateProductBrand para verificar a marca do produto na lista de chegada;
 * Função inacabada
 */
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

/**
 * Função para modificar a categoria de uma seção.
 * @param sectionarray - Ponteiro para o array de seções.
 * @param section - Referência para a seção
 * Explicação:
 * Pede a categoria e a secção ao utilizador, no qual é secção é feita uma verificação com a função validatevalidateSectionID
 * a ver se a mesma existe
 * Percorre as secções todas até encontrar a secção que foi inserida e muda a categoria dessa secção
 */
void mudaCategoria(Section* sectionarray, Section& section){
    std::string mudacategoria;
    char sectionchange;
    // Loop para garantir que o usuário insira uma seção válida
    do {
        std::cout << "Digite a seccao" << std::endl;
        std::cin >> sectionchange;

        if(!validateSectionID(sectionchange, sectionarray, section.tamanho)){
            std::cout << "Seccao invalida. Tente novamente." << std::endl;
        } else {
            std::cout << "Foi encontrado Categoria!" << std::endl;
            break; // Sai do loop se a secção for válida
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
/**
 * Função para adicionar uma nova secção
 *
 * @param sectionarray - Ponteiro para o array de secções.
 * @param section - Referência para a secção que será adicionada.
 * @return - Ponteiro para o novo array de secções
 * Explicação:
 * Pede ao utilizador qual secção, a capacidade e a Categoria que deseja adicionar;
 * É criado um novo array onde é mandado todos dados do sectionarray para o novo array;
 * Com os dados inseridos pelo utilizador são enviaados para a ultima posição que foi adicionada;
 * Por fim é atualziado o tamanho da secçao (section.tamanho) e retorna o ponteiro para o novo array de secções
 */
Section* addSection(Section*& sectionarray, Section& section) {
    char sectionID;
    int sectionCapacity;
    std::string sectionCategory;
    std::cout << "Digite o ID da seccao: " << std::endl;
    std::cin >> sectionID;
    do {
        std::cout << "Digite a capacidade da seccao (valores entre 3 e 6): " << std::endl;
        std::cin >> sectionCapacity;
        if (sectionCapacity >= 3 && sectionCapacity <= 6) {
            std::cout << "Capacidade Valida" << std::endl;
            break;
        } else {
            std::cout << "Capacidade invalida. Tente novamente." << std::endl;
        }
    } while (!(sectionCapacity >= 3 && sectionCapacity <= 6));

    std::cout << "Digite a Categoria: " << std::endl;
    std::cin >> sectionCategory;

    int novoTamanho = section.tamanho + 1;
    Section* novoArray = new Section[novoTamanho];

    for (int i = 0; i < section.tamanho; ++i) {
        novoArray[i] = sectionarray[i];
    }

    novoArray[novoTamanho - 1].id = sectionID;
    novoArray[novoTamanho - 1].capacity = sectionCapacity;
    novoArray[novoTamanho - 1].category = sectionCategory;

    delete[] sectionarray;

    sectionarray = novoArray;

    section.tamanho = novoTamanho;

    return novoArray;
}


//3.2 Implementar promoção
/**
 * Esta função aplica uma promoção a uma seccão específica do armazém, reduzindo o preço das peças
 * dessa seccão por uma certa duração e aumentando a
 * probabilidade de venda das peças afetadas.
 * @param section Referência à struct section contendo informações sobre o armazém.
 * @param sectionsArray Ponteiro para o array de seções do armazém.
 * @param totalCapacity Capacidade total do armazém.
 */
void promocao(Section& section, Section* sectionsArray, int totalCapacity){
    char id;
    int desconto;
    int duracao;
    std::cout << "Escolheu a opcao 2 - Promocao" << std::endl;
    std::cout << "Duracao da promocao (em dias): " << std::endl;
    std::cin >> duracao;
    std::cout << "Digite o ID da seccao que ira ter o desconto: " << std::endl;
    std::cin >> id;
    std::cout << "Percentagem de desconto: " << std::endl;
    std::cin >> desconto;
    for(int k = 0; k < duracao; k++) {
        for (int i = 0; i < section.tamanho; i++) {
            for (int j = 0; j < totalCapacity; j++) {
                if (id == sectionsArray[i].id && sectionsArray[i].category == section.listaEspera[j].category) {
                    int novoPreco = section.listaEspera[j].price - ((section.listaEspera[j].price * desconto) / 100);
                    section.listaEspera[j].sellprob = std::min(section.listaEspera[j].sellprob + 15, 100);
                    section.listaEspera[j].price = novoPreco;
                }
            }
        }
    }
}


//3.5 - Gravar Armazém em Ficheiros
/**
 * Função para gravar a lista de peças em ficheiros
 * @param listaChegada - Ponteiro para a lista de peças
 * Explicação:
 * Abre o arquivo "listachegada.txt" para escrita e verifica se foi aberto
 * Envia as peças para dentro do ficheiro
 * Após isso fecha o ficherio
 */
void gravarlistachegada(Peca* listaChegada){
    std::fstream file("listachegada.txt", std::ios::out);
    if(file.is_open()){
        file << "Lista de Chegada" << std::endl;
        for (int i = 0; i < 15; ++i) {
            file << listaChegada[i].category << " | " << listaChegada[i].brand << " | " << listaChegada[i].serialNumber << " | " << listaChegada[i].price << std::endl;
        }
        file.close();
        std::cout << "Gravado com sucesso"<< std::endl;
    } else {
        std::cerr << "Erro ao guardar lista de chegada no ficheiro" << std::endl;
    }
}

/**
 * Função para gravar as secções do armazem.
 *
 * @param sectionsArray - Ponteiro para o array de seções do armazém.
 * @param section - Referência para a seção do armazém.
 * Explicação:
 * Abre o arquivo "Armazem.txt" para escrita e verifica se foi aberto
 * Envia as secções para dentro do ficheiro
 * Após isso fecha o ficherio
 */
void gravararmazem(Section* sectionsArray, Section& section){
    std::fstream file("Armazem.txt", std::ios::out);
    if(file.is_open()){
        file << "  Seccao " << " | " << " Categoria " << " | " << " Capacidade " << " | " << " Quantidade " << " | " << " Facturacao " << " | " << std::endl;
        for (int i = 0; i < section.tamanho; ++i) {
            file << sectionsArray[i].id << " | " << sectionsArray[i].category << " | " << sectionsArray[i].capacity << " | " << sectionsArray[i].quantity << " | " << "0" << std::endl;
        }
        file.close();
        std::cout << "Gravado armazem com sucesso" << std::endl;
    } else {
        std::cout << "Erro ao guardar armazem no ficheiro" << std::endl;
    }
}

/**
 * Função para gravar o valor total de facturamento armazem
 *
 * @param section - Referência para a seção do armazém.
 * Explicação:
 * Abre o arquivo "FacturamentoArmazem.txt" para escrita e verifica se foi aberto
 * Envia o valor total
 * Após isso fecha o ficherio
 */
void gravartotalfacturamente(Section& section){
    std::fstream file("FacturamentoArmazem.txt", std::ios::out);
    if(file.is_open()){
        file << "Total Facturamento Armazem: " << section.totalIncome << " $";
        file.close();
        std::cout << "Gravado Total Armazem com sucesso" << std::endl;
    } else {
        std::cout << "Erro ao gravar Total Armazem no ficheiro" << std::endl;
    }
}