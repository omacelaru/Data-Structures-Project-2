//
// Created by macelaru on 18.04.2023.
//
#include "Meniu.h"

void Meniu::start() {
    std::ifstream f("../abce.in");
    std::ofstream g("../abce.out");

    int X, Y, Q, decizie;
    int i;

    f >> Q;
    for (i = 0; i < Q; i++) {
        f >> decizie;
        switch (decizie) {
            case 1: {
                f >> X;
                tree.insert(X);
                break;
            }
            case 2: {
                f >> X;
                tree.remove(tree.root, X);
                break;
            }
            case 3: {
                f >> X;
                g << tree.cauta(tree.root, X) << '\n';
                break;
            }
            case 4: {
                f >> X;
                g << tree.cel_mai_mare_nr_mai_mic(tree.root, X) << '\n';
                break;
            }
            case 5: {
                f >> X;
                g << tree.cel_mai_mic_nr_mai_mare(tree.root, X) << '\n';
                break;
            }
            case 6: {
                f >> X >> Y;
                tree.interval.clear();
                tree.afiseazaInInterval(tree.root, X, Y);
                for (auto x: tree.interval)
                    g << x << " ";
                g << '\n';
                break;
            }
            default:
                break;
        }
    }
    f.close();
    g.close();
}
