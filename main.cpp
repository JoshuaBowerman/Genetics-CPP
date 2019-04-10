#include <iostream>
#include "Instance.h"
#include "Instance.cpp"
#include "Species.h"

using namespace std;


#define NUMBER_GENERATIONS 1000

Instance getAllC();

int main() {
    cout << "Generation, A AVG Score, B AVG Score, A Best Score, B Best Score" << endl;

    Species A = Species();
    Species B = Species();


    for(int i = 0; i < NUMBER_GENERATIONS; i++){
       // A.competeWith(&B);
        Instance h = getAllC();
        A.competeWith(&h);
        B.competeWith(&h);
        float t = 0;
        for(int h = 0; h < CHROMOSOME_SIZE; h++){
            t += B.getBest().chromosome[h];
        }
        cout << i + 1 << "," << A.getAverage() << "," << B.getAverage() << "," << A.getBest().score << "," << B.getBest().score << "," << t/CHROMOSOME_SIZE << endl;

        A.buildNextGeneration();
        B.buildNextGeneration();
    }

    return 0;
}

Instance getTitForTat(){
    bool chromosome[CHROMOSOME_SIZE];
    chromosome[0] = false;
}

Instance getAllC(){
    Instance h = Instance();
    for(int i = 0; i < CHROMOSOME_SIZE;i++){
        h.chromosome[i] = false;
    }
}