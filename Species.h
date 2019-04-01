//
// Created by Joshua on 2019-03-23.
//

#ifndef GENETICS_SPECIES_H
#define GENETICS_SPECIES_H

#include <xstring>
#include "Instance.h"

#define POPULATION_SIZE 50



class Species {

public:

    int generation = 0;
    Instance population[POPULATION_SIZE];

    Species();
    Species(std::string fileLocation);
    void createGeneration();
    float getGenerationScore();
    void exportToFile(std::string fileLocation);
    void competeWith(Species opponent);

    //TODO: Implement Species compete with single instance
    void competeWith(Instance opponent);


};


#endif //GENETICS_SPECIES_H
