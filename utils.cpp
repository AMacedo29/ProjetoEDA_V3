#include <iostream>
#include <cstdlib> // Para a funcao rand()
#include <fstream>
#include <string>
#include <ctime> // Para a funcao time()
//using namespace std;

/**
* calcula um numero inteiro aleatorio dentro do intervalo especificado
*
* @param minVal o valor minimo do intervalo
* @param maxVal o valor maximo do intervalo
* @return um numero inteiro aleatório dentro do intervalo [minVal, maxVal]
*/
int calculateRandomNumber(int minVal, int maxVal) {
    return minVal + (rand() % (maxVal + 1 - minVal));
}

/**
 * retorna uma marca aleatoria do arquivo "marcas.txt".
 *
 * @return uma marca lida aleatoriamente do arquivo "marcas.txt".
 */
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

/**
 * retorna uma categoria aleatoria do arquivo "categorias.txt".
 *
 * @return uma categoria lida aleatoriamente do arquivo "categorias.txt".
 */
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

