//
// Created by Josh on 2019-03-19.
//

#ifndef GENETICS_INSTANCE_H
#define GENETICS_INSTANCE_H

#define MEMORY_DEPTH 3
#define CHROMOSOME_SIZE ((1 << (MEMORY_DEPTH + 1)) - 1)

#define MUTATION_RATE 10000

#define NUMBER_ROUNDS 10

class Instance {
    int generation = 0;
    int score = 0;
    bool chromosome[CHROMOSOME_SIZE];


public:
    Instance breedWith(Instance partner);
    std::string toString();
    Instance();
    Instance(std::string Source);
    void mutateSelf();
    void competeWith(Instance opponent);


};


#endif //GENETICS_INSTANCE_H
