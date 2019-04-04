#include <iostream>
#include "Instance.cpp"
#include "Species.h"

using namespace std;


#define NUMBER_GENERATIONS 1000

int main() {
    cout << "Generation, A AVG Score, B AVG Score, A Best Score, B Best Score" << endl;

    Species A = Species();
    Species B = Species();

    for(int i = 0; i < NUMBER_GENERATIONS; i++){
        A.competeWith(&B);
        cout << i + 1 << "," << A.getAverage() << "," << B.getAverage() << "," << A.getBest().score << "," << B.getBest().score << endl;

        A.buildNextGeneration();
        B.buildNextGeneration();
    }


    return 0;
}