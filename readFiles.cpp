#include "readFiles.h"
#include <iostream>
#include <fstream>
#include <string>

const int MAX_MARCAS = 76;
const int MAX_CATEGORIAS = 22;

std::string readMarcas() {
    std::ifstream myFile("marcas.txt"); // Abre o arquivo "nomes.txt"
    std::string marcas[MAX_MARCAS]; // Array para armazenar os nomes lidos do arquivo
    std::string linha; // Variável temporária para armazenar cada linha do arquivo
    std::string arrayMarcas;
    int tamanho = 0; // Variável para controlar o número de nomes lidos

    // Verifica se o arquivo foi aberto corretamente
    if (myFile.is_open()) {
        // Lê cada linha do arquivo e armazena em nomes
        while (std::getline(myFile, linha) && tamanho < MAX_MARCAS) {
            marcas[tamanho++] = linha;
        }
        myFile.close(); // Fecha o arquivo após a leitura
    } else {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return ""; // Retorna 1 para indicar erro
    }
    for (int i = 0; i < tamanho; ++i) {
        arrayMarcas += marcas[i] + "\n"; // Adiciona o nome seguido de uma quebra de linha
    }
    return arrayMarcas;
}

std::string readCategorias() {
    std::ifstream myFile("categorias.txt"); // Abre o arquivo "nomes.txt"
    std::string categorias[MAX_CATEGORIAS]; // Array para armazenar os nomes lidos do arquivo
    std::string linha; // Variável temporária para armazenar cada linha do arquivo
    std::string arrayCategorias;
    int tamanho = 0; // Variável para controlar o número de nomes lidos

    // Verifica se o arquivo foi aberto corretamente
    if (myFile.is_open()) {
        // Lê cada linha do arquivo e armazena em nomes
        while (std::getline(myFile, linha) && tamanho < MAX_CATEGORIAS) {
            categorias[tamanho++] = linha;
        }
        myFile.close(); // Fecha o arquivo após a leitura
    } else {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return ""; // Retorna 1 para indicar erro
    }
    for (int i = 0; i < tamanho; ++i) {
        arrayCategorias += categorias[i] + "\n"; // Adiciona o nome seguido de uma quebra de linha
    }
    return arrayCategorias;
}