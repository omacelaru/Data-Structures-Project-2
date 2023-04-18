//
// Created by macelaru on 18.04.2023.
//

#ifndef DATA_STRUCTURES_PROJECT_2_ARBOREBINAR_H
#define DATA_STRUCTURES_PROJECT_2_ARBOREBINAR_H

#include <memory>
#include <vector>
#include "Nod.h"

class ArboreBinar {
public:
    std::vector<int> interval;

    std::shared_ptr<Nod> root;

    ArboreBinar();

    void insert(int val);

    bool remove(std::shared_ptr<Nod> &root, int val);

    std::shared_ptr<Nod> findMin(std::shared_ptr<Nod> node);

    int cauta(std::shared_ptr<Nod> root, int val);

    int cel_mai_mare_nr_mai_mic(std::shared_ptr<Nod> root, int X);

    int cel_mai_mic_nr_mai_mare(std::shared_ptr<Nod> root, int X);

    void afiseazaInInterval(std::shared_ptr<Nod> root, int X , int Y);
};


#endif //DATA_STRUCTURES_PROJECT_2_ARBOREBINAR_H
