//
//  matrice.cpp
//  Labirint-joc
//
//  Created by CLAUDIA-DENISA on 11.06.2024.
//

#include "main.h"
#include <string>
#include <iostream>

Matrice::Matrice(int r, int c) : randuri(r), coloane(c) {
    if(r==c && r==6)
    {M = {{1, 0, 0, 0, 0, 2},
        {1, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0}
    };}
    else if(r==8)
    {
        M = {{1, 0, 0, 0, 0, 0, 0, 2},
            {1, 0, 1, 0, 1, 1, 1, 1},
            {0, 0, 1, 0, 0, 0, 0, 1},
            {0, 1, 0, 1, 1, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 1, 0, 0, 0}
        };
    }
    else if(r==10)
    {
        M = {{1, 0, 0, 1, 0, 0, 0, 1, 0, 2},
            {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 1, 0, 1, 0, 0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
            {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
            {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
            {1, 1, 0, 1, 1, 0, 1, 0, 0, 1},
            {0, 0, 0, 1, 0, 0, 0, 0, 1, 1}
        };
    }
}


bool Matrice::mutare(int x, int y) const {
    return x >= 0 && x < randuri && y >= 0 && y < coloane && (M[x][y] == 0 || M[x][y] == 2);
}

pair<int, int> Matrice::start() const {
    return {randuri-1 , 0};
}

pair<int, int> Matrice::sfarsit() const {
    return {0, coloane - 1};
}

void Matrice::pion(int x, int y, bool ocupat) {
    if (ocupat) {
        M[x][y] = 2;
    } else {
        M[x][y] = 0; 
    }
}

ostream& operator<<(ostream& os, const Matrice& matrice) {
    for (const auto& rand : matrice.M) {
        for (int celula : rand) {
            if (celula == 1) {
                os << "* ";
            } else if (celula == 2) {
                os<< "! ";
            } else { os<<". ";
            }
        }
        os << endl;
    }
    return os;
}
