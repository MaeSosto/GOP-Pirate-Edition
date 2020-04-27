//
// Created by Marti on 12/04/2018.
//

#include "../include/Auxiliary_functions.h"

#ifndef CASELLA_H
#define CASELLA_H

class Giocatore;
class GOP;

class Casella{

private:
    int numero;
    int effetto;



public:
    Casella(int n);
    virtual ~Casella();
    bool grafica_casella(Giocatore* l_giocatori[], int j, int num_giocatori, int num_caselle);

    //METODI
    void casDadi(Giocatore* l_giocatori[], int j);
    void casForwardN(Giocatore* l_giocatori[], int j);
    void casCard();
    void casBack5(Giocatore* l_giocatori[], int j);
    void casAction5(Giocatore* l_giocatori[], int j, bool &b);
    void casMoveToN(Giocatore* l_giocatori[], int j, int num_caselle);
    void casStill(Giocatore* l_giocatori[], int j);
    void casJoin(Giocatore* l_giocatori[], int j, int num_giocatori);
    void casScambio(Giocatore* l_giocatori[], int j, int num_giocatori);
    void casOver(Giocatore* l_giocatori[], int j);

    //Setters and getters
    void setEffetto(int effetto);


};


#endif // CASELLA_H




