//
// Created by macelaru on 18.04.2023.
//

#ifndef DATA_STRUCTURES_PROJECT_2_NOD_H
#define DATA_STRUCTURES_PROJECT_2_NOD_H
#include <memory>

class Nod {
public:
    int val;
    std::shared_ptr<Nod> stg;
    std::shared_ptr<Nod> drp;

    Nod(int val);
};


#endif //DATA_STRUCTURES_PROJECT_2_NOD_H
