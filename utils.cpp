#include <iostream>
#include <cstdlib> // Para a funcao rand()
#include <fstream>
#include <string>
#include <ctime> // Para a funcao time()
//using namespace std;


int calculateRandomNumber(int minVal, int maxVal) {
    return minVal + (rand() % (maxVal + 1 - minVal));
}

std::string getRandomMarca() {
    std::ifstream myFile("marcas.txt"); // Abre o arquivo "marcas.txt"
    std::string linha; // Variável temporária para armazenar cada linha do arquivo
    int numLines = 0;

    // Conta o número de linhas
    while (std::getline(myFile, linha)) {
        ++numLines;
    }

    // Gera um número de linha aleatório
    int randomLineNum = calculateRandomNumber(0, numLines - 1);

    // Obtém a linha aleatória
    myFile.clear(); // Limpa a flag EOF (fim do ficheiro)
    myFile.seekg(0); // Volta ao início do arquivo
    for (int i = 0; i <= randomLineNum; ++i) {
        std::getline(myFile, linha);
    }

    return linha; // Retorna a marca aleatória
}

std::string getRandomCategoria() {
    std::ifstream myFile("categorias.txt"); // Abre o arquivo "categorias.txt"
    std::string linha; // Variável temporária para armazenar cada linha do arquivo
    int numLines = 0;

    // Conta o número de linhas
    while (std::getline(myFile, linha)) {
        ++numLines;
    }

    // Gera um número de linha aleatório
    int randomLineNum = calculateRandomNumber(0, numLines - 1);

    // Obtém a linha aleatória
    myFile.clear(); // Limpa a flag EOF (fim do ficheiro)
    myFile.seekg(0); // Volta ao início do arquivo
    for (int i = 0; i <= randomLineNum; ++i) {
        std::getline(myFile, linha);
    }

    return linha; // Retorna a categoria aleatória
}