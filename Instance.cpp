//
// Created by Josh on 2019-03-19.
//

#include "Instance.h"
using namespace std;
Instance::Instance() {
    //Generate Chromosome
    for(int i = 0; i < CHROMOSOME_SIZE;i++){
        chromosome[i] = rand() % 2;
    }
    generation = 0;
}

Instance::Instance(string Source) {
    for(int i = 0; i < CHROMOSOME_SIZE; i++){
        chromosome[i] = Source.c_str()[i] == '1';
    }
}

string Instance::toString() {
    string res = "";

    for(int i = 0; i < CHROMOSOME_SIZE; i++){
        res += chromosome[i] ? "1" : "0";
    }

    return res;
}

void Instance::mutateSelf() {
    for(int i = 0; i < CHROMOSOME_SIZE; i++){
        chromosome[i] = ((rand() % MUTATION_RATE )== 0) ? !chromosome[i] : chromosome[i];
    }
}

Instance Instance::breedWith(Instance partner){
    //Generate String
    string a = this->toString();
    string b = partner.toString();

    string c = "";
    for(int i = 0; i < CHROMOSOME_SIZE i++){
        c += (rand() % 2) ? a.c_str()[i] : b.c_str()[i];
    }
    Instance child = Instance(c);
    child.mutateSelf();
    child.generation = generation + 1;
    return child;
}

void Instance::competeWith(Instance opponent) {
    for(int round = 0; round < NUMBER_ROUNDS; round++){
        bool actiona = false;
        bool actionb = false;
        if(round == 0){
            actiona = chromosome[0];
            actionb = opponent.chromosome[0];
        }else if(){

        }
    }
}