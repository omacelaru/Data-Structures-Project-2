//
// Created by macelaru on 18.04.2023.
//
#include <iostream>

#include "ArboreBinar.h"

using namespace std;

ArboreBinar::ArboreBinar() : root(nullptr) {}

void ArboreBinar::insert(int val) {

    shared_ptr<Nod> newNod = make_shared<Nod>(val);

    if (root == nullptr) {
        root = newNod;
        return;
    }

    shared_ptr<Nod> curr = root;

    while (true) {
        if (val < curr->val) {
            if (curr->stg == nullptr) {
                curr->stg = newNod;
                return;
            } else
                curr = curr->stg;
        } else {
            if (curr->drp == nullptr) {
                curr->drp = newNod;
                return;
            } else
                curr = curr->drp;
        }
    }
}

bool ArboreBinar::remove(std::shared_ptr<Nod> &root, int val) {
    if (root == nullptr) {
        return false; // Valoarea nu există în arbore
    }
    if (val < root->val) {
        return remove(root->stg, val);
    } else if (val > root->val) {
        return remove(root->drp, val);
    } else {
        if (root->stg == nullptr && root->drp == nullptr) { // Nodul nu are copii
            root = nullptr;
        } else if (root->stg == nullptr) { // Nodul are doar copii în dreapta
            root = root->drp;
        } else if (root->drp == nullptr) { // Nodul are doar copii în stânga
            root = root->stg;
        } else { // Nodul are ambii copii
            std::shared_ptr<Nod> replacement = findMin(root->drp);
            root->val = replacement->val;
            remove(root->drp, replacement->val);
        }
        return true;
    }
}

std::shared_ptr<Nod> ArboreBinar::findMin(std::shared_ptr<Nod> node) {
    while (node->stg != nullptr) {
        node = node->stg;
    }
    return node;
}

int ArboreBinar::cauta(std::shared_ptr<Nod> root, int val) {
    if (root == nullptr) {
        return 0;
    }

    std::shared_ptr<Nod> curr = root;

    while (curr != nullptr) {
        if (curr->val == val) {
            return 1;
        } else if (val < curr->val) {
            curr = curr->stg;
        } else {
            curr = curr->drp;
        }
    }
    return 0;
}

int ArboreBinar::cel_mai_mare_nr_mai_mic(std::shared_ptr<Nod> root, int X) {
    if (root == nullptr) {
        return -1;
    }

    int Y = -1;
    std::shared_ptr<Nod> curr = root;

    while (curr != nullptr) {
        if (curr->val <= X) {
            Y = curr->val;
            curr = curr->drp;
        } else {
            curr = curr->stg;
        }
    }

    return Y;
}

int ArboreBinar::cel_mai_mic_nr_mai_mare(std::shared_ptr<Nod> root, int X) {
    if (root == nullptr) {
        return -1;
    }

    int Y = -1;
    std::shared_ptr<Nod> curr = root;

    while (curr != nullptr) {
        if (curr->val >= X) {
            Y = curr->val;
            curr = curr->stg;
        } else {
            curr = curr->drp;
        }
    }

    return Y;
}

void ArboreBinar::afiseazaInInterval(std::shared_ptr<Nod> root, int X, int Y) {
    if (root == nullptr) {
        return;
    }

    if (root->val >= X) {
        afiseazaInInterval(root->stg, X, Y);
    }

    if (root->val >= X && root->val <= Y) {
        interval.push_back(root->val);
    }

    if (root->val <= Y) {
        afiseazaInInterval(root->drp, X, Y);
    }
}

