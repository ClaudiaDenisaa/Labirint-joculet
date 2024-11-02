//
//  matrice.h
//  Labirint-joc
//
//  Created by CLAUDIA-DENISA on 10.06.2024.
//

#ifndef MATRICE_H
#define MATRICE_H

//#include <utility> 
#include <vector>
#include "main.h"
using namespace std;

class Matrice {
private:
    vector<vector<int>> M;
    int randuri, coloane;
    
public:
    Matrice(int r, int c);
    friend ostream& operator<<(ostream& os, const Matrice& matrice);
    bool mutare(int x, int y) const;
    pair<int, int> start() const;
    pair<int, int> sfarsit() const;
    void pion(int x, int y,bool ocupat = true);
};

#endif /* MATRICE_H */
