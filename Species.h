//
// Created by Joshua on 2019-03-23.
//

#ifndef GENETICS_SPECIES_H
#define GENETICS_SPECIES_H

#include <xstring>
#include "Instance.h"

#define NUMBER_BREEDERS 16
#define POPULATION_SIZE (((NUMBER_BREEDERS * NUMBER_BREEDERS) - NUMBER_BREEDERS) / 2)



class Species {

public:

    int generation = 0;
    Instance population[POPULATION_SIZE];

    Species();
    Species(std::string fileLocation);
    float getGenerationScore();
    void exportToFile(std::string fileLocation);
    void competeWith(Species opponent);
    void competeWith(Instance opponent);
    void buildNextGeneration();


};


#endif //GENETICS_SPECIES_H
