//
//  meniu.cpp
//  Labirint-joc
//
//  Created by CLAUDIA-DENISA on 28.06.2024.
//

#include "meniu.hpp"
#include "main.h"
#include <string>
#include <iostream>

void jocul(Matrice& M){
    auto pozitie_start = M.start();
    Jucator J(pozitie_start.first, pozitie_start.second);

    auto pozitie_jucator = J.get_pozitie();
    M.pion(pozitie_jucator.first, pozitie_jucator.second);
    
    cout << M;
    cout << J << endl;

    char directie;
    while (!J.final_joc(M)) {
        cout << "Executa o mutare (apasa o tasta: w/a/s/d): ";
        cin >> directie;cout<<endl;
        J.miscare(directie, M);
        auto pozitie_jucator = J.get_pozitie();
        M.pion(pozitie_jucator.first, pozitie_jucator.second);
        cout << M;
        cout << J << endl;
    }
    
    cout << "----------------------------------------" << endl;
    cout << "Felicitari! Ai ajuns la finalul jocului!" << endl;
    cout << "----------------------------------------" << endl;
    
}

void meniu(){
    
    int opt;
    
    while(true){
        cout << "Meniu:" << endl;
        cout << "1. Joc 6x6" << endl;
        cout << "2. Joc 8x8" << endl;
        cout << "3. Joc 10x10" << endl;
        cout << "4. Iesire" << endl;
        cout << "Alege o optiune: ";
        cin >> opt;
        cout << endl;
        
        switch(opt){
            case 1: {Matrice M(6, 6);
                jocul(M);
                break;}
            case 2:{ Matrice M(8, 8);
                jocul(M);
                break;}
            case 3: {Matrice M(10, 10);
                jocul(M);
                break;}
            case 4:cout<<"Iesire din joc."<<endl;
                return;
            default:   cout<<endl<< "Optiune invalida! Te rog sa alegi din nou." << endl;
                break;
        }
    }
}
