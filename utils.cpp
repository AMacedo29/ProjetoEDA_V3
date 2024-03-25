#include <iostream>
#include <cstdlib> // For the rand() function
using namespace std;


int calculateRandomNumber(int minVal, int maxVal) {
    return minVal + (rand() % (maxVal + 1 - minVal));
}
