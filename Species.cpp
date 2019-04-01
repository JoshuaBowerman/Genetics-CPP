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

void Species::competeWith(Species opponent) {

    for(int i = 0; i < POPULATION_SIZE; i++){
        this->population[i].competeWith(opponent.population[i]);
    }

}

void Species::competeWith(Instance opponent) {
    for(int i = 0; i < POPULATION_SIZE; i++){
        opponent.competeWith(this->population[i]);
    }
    opponent.score = opponent.score / POPULATION_SIZE;

}

void Species::buildNextGeneration() {

}