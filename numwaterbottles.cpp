#include <iostream>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    
    int total = numBottles;
    int empty = numBottles;

    while(empty >= numExchange) {
        int newBottle = empty / numExchange;
        total += newBottle;
        empty = newBottle + (empty % numExchange);
    }

    return total;
}

int main() {

    int numBottles = 9;
    int numExchange = 3;

    cout << numWaterBottles(numBottles, numExchange);

    return 0;
}
