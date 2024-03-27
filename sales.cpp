#include <iostream>
#include "pecas.h"
#include "utils.h"
#include "sales.h"

int totalSales = 0;

void sellPeca(Peca* listaChegada) {
    int randNum = calculateRandomNumber(0,100);
    for (int i=0 ; i<10 ; i++)
    // Se o número aleatório for menor ou igual à probabilidade de venda, a peça é vendida
    if (randNum <= listaChegada[i].sellprob){ // esta errado pq n podemos vender o que esta na lista de chegada temos q
        totalSales += listaChegada[i].price;  // vender é o q esta nas sections é so mudar a linha 8, 10 (i<10), 12, 13;
    }
}

// Função para obter o valor total das vendas
int getTotalSales() {
    return totalSales;
}
