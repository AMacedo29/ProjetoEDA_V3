#include <iostream>
#include <cstdlib> // For the rand() function
#include <ctime>   // For the time() function

using namespace std;

int calculateRancomNumber(int minVal, int maxVal) {
    return minVal + (rand() % (maxVal + 1 - minVal));
}
