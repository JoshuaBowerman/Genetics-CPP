//
// Created by Joshua on 2019-03-23.
//

#include "Species.h"

float Species::getGenerationScore() {
    float total = 0;

    for(int i = 0; i < POPULATION_SIZE; i++){
        total += population[i].score;
    }

    return total / POPULATION_SIZE;
}

Species::Species(){
    this->generation = 0;
    for(int i = 0; i < POPULATION_SIZE; i++){
        this->population[i] = Instance();
    }
};

void Species::competeWith(Species *opponent) {

    for(int i = 0; i < POPULATION_SIZE; i++){
        population[i].competeWith(&opponent->population[i]);
    }

}

void Species::competeWith(Instance *opponent) {
    for(int i = 0; i < POPULATION_SIZE; i++){
        opponent->competeWith(&population[i]);
    }
    opponent->score = opponent->score / POPULATION_SIZE;

}

void Species::buildNextGeneration() {
    Instance breeders[NUMBER_BREEDERS];

    //Find the top x instances
    for(int i = 0; i < NUMBER_BREEDERS;i++){
        int best = 0;
        for(int j = 0; j < POPULATION_SIZE;j++){
            if(population[j].score > population[best].score){
                best = j;
            }
        }
        breeders[i] = population[best];
        population[best].score = -100000;
    }

    //breed them
    int index = 0;
    for(int i = 0; i < NUMBER_BREEDERS; i++){
        for(int j = i; j < NUMBER_BREEDERS; j++){
            if(i != j){
                population[index++] = breeders[i].breedWith(breeders[j]);
            }
        }
    }
    this->generation++;
}

Instance Species::getBest() {
    Instance best = population[0];
    for(int i = 0; i < POPULATION_SIZE; i++){
        if(population[i].score > best.score){
            best = population[i];
        }
    }
    return best;
}

float Species::getAverage(){
    float total = 0;
    for(int i = 0; i < POPULATION_SIZE; i++){
        total += population[i].score;
    }
    return total / POPULATION_SIZE;
}