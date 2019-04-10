//
// Created by Josh on 2019-03-19.
//

#include "Instance.h"

using namespace std;

Instance::Instance() {
    //Generate Chromosome
    for (int i = 0; i < CHROMOSOME_SIZE; i++) {
        chromosome[i] = rand() % 2;
    }
    generation = 0;
}

Instance::Instance(string Source) {
    for (int i = 0; i < CHROMOSOME_SIZE; i++) {
        chromosome[i] = Source.c_str()[i] == '1';
    }
}

string Instance::toString() {
    string res = "";

    for (int i = 0; i < CHROMOSOME_SIZE; i++) {
        res += chromosome[i] ? "1" : "0";
    }

    return res;
}

void Instance::mutateSelf() {
    for (int i = 0; i < CHROMOSOME_SIZE; i++) {
        chromosome[i] = ((rand() % MUTATION_RATE) == 0) ? !chromosome[i] : chromosome[i];
    }
}

Instance Instance::breedWith(Instance partner) {
    //Generate String
    string a = this->toString();
    string b = partner.toString();

    string c = "";
    for (int i = 0; i < CHROMOSOME_SIZE; i++) {
        c += (rand() % 2) ? a.c_str()[i] : b.c_str()[i];
    }
    Instance child = Instance(c);
    child.mutateSelf();
    child.generation = generation + 1;
    child.score = 0;
    return child;
}

void Instance::competeWith(Instance *opponent) {
    bool actionHistoryA[NUMBER_ROUNDS];
    bool actionHistoryB[NUMBER_ROUNDS];
    for(int i = 0; i < NUMBER_ROUNDS; i++){
        actionHistoryA[i] = false;
        actionHistoryB[i] = false;
    }
    for (int round = 0; round < NUMBER_ROUNDS; round++) {
            //Calculate offset
            int offset = (1 << (round < MEMORY_DEPTH ? round : MEMORY_DEPTH)) - 1;  //  2 ^(round) - 1

            //Calculate Action Index Value
            int indexA = 0;
            int indexB = 0;
            for(int i = round; i > round - (round > MEMORY_DEPTH ? MEMORY_DEPTH : round);i--){
                indexA = (indexA << 1) + actionHistoryB[i] ? 1 : 0;
                indexB = (indexB << 1) + actionHistoryA[i] ? 1 : 0;
            }

            //Commit actions
            actionHistoryA[round] = this->chromosome[offset + indexA] ? true : false;
            actionHistoryB[round] = opponent->chromosome[offset + indexB] ? true : false;

        //Calculate Scores

        /*
         *         Coop | Defect
         *    Coop -1,-1| -20,0
         *         ------------
         *  Defect 0,-20| -10,-10
         */

        if(this->generation > 40 || opponent->generation > 40){
            cout << endl;
        }
        if (actionHistoryA[round] && actionHistoryB[round]) {
            this->score -= 1;
            opponent->score -= 1;
        } else if (actionHistoryA[round] & !actionHistoryB[round]) {
            this->score -= 20;
            opponent->score -= 0;
        } else if (!actionHistoryA[round] & actionHistoryB[round]) {
            this->score -= 0;
            opponent->score -= 20;
        } else if (!actionHistoryA[round] & !actionHistoryB[round]) {
            this->score -= 10;
            opponent->score -= 10;
        }
    }
}