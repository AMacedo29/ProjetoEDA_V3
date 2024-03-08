#include <iostream> // For the std::cout and std::endl functions
#include "utils.h"
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function


int pecasPrice() {
    // Initialize random seed
    srand(time(0));

    for (int i = 0; i < 10; ++i) { // Loop que imprime 10 preços diferentes

        // Generate a number between 2 and 180 and multiply it by 5 ex: 2*5 = 10 and 180*5 = 900
        int precoPecas = calculateRandomNumber(2, 180) * 5;
        // We need to switch the i+1 to the peca name
        std::cout << "The random price of item " << i+1 << " is: " << precoPecas << " euros" << std::endl;
    }

    return 0;
}
