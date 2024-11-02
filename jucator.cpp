//
//  jucator.cpp
//  Labirint-joc
//
//  Created by CLAUDIA-DENISA on 10.06.2024.
//

#include <iostream>
#include <string.h>
#include "main.h"

Jucator::Jucator(int startX, int startY) : x(startX), y(startY) {}

void Jucator::miscare(char directie, Matrice& M) {
    int nouX = x;
    int nouY = y;
    switch (directie) {
        case 'w': nouX--; break; // in sus
        case 's': nouX++; break; // in jos
        case 'a': nouY--; break; // in stanga
        case 'd': nouY++; break; // in dreapta
        default: return; // direcție invalidă si nu se face nici o mutare, ramane in acelasi loc
    }
    if (M.mutare(nouX, nouY)) {
        M.pion(x, y, false);  //se sterge + de pe pozitia anterioara
        x = nouX;
        y = nouY;
        M.pion(x, y, true);  //se muta pionul (+)
    }
    
}

pair<int, int> Jucator::get_pozitie() const {
    return {x, y};
}
 

bool Jucator::final_joc(const Matrice& M) const {
    auto pozitie_finala = M.sfarsit();
    return x == pozitie_finala.first && y == pozitie_finala.second;
}

ostream& operator<<(ostream& os, const Jucator& jucator) {
    os<<endl << "Pozitia jucatorului: (" << jucator.x << ", " << jucator.y << ")";
    return os;
}
