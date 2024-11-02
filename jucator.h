//
//  jucator.h
//  Labirint-joc
//
//  Created by CLAUDIA-DENISA on 10.06.2024.
//

#ifndef JUCATOR_H
#define JUCATOR_H


#include "main.h"
#include <utility> 
using namespace std;

class Jucator {
    int x, y;
    
public:
    Jucator(int startX, int startY);
    pair<int, int> get_pozitie() const;
    void miscare(char d, Matrice& M);
    friend ostream& operator<<(ostream& os, const Jucator& jucator);
    bool final_joc(const Matrice& M) const;
};

#endif /* JUCATOR_H */
