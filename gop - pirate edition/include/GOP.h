//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#ifndef GOP_H
#define GOP_H
#define sei 6
#define sessantacinque 65
#define quarantadue 42
#include "Auxiliary_functions.h"

class Giocatore;
class Casella;
class Carta;

class GOP
{
public:
    GOP();
    virtual ~GOP();


    Giocatore *const *getL_giocatori() const;

protected:

private:
    //Campi
    int num_giocatori;
    int num_caselle;
    int num_carte;
    int round;
    int next_turno;
    Giocatore* l_giocatori[sei];
    Casella* l_caselle[sessantacinque];
    Carta* mazzo[quarantadue];

    //GOP.cpp
    void show_players();
    void set_players();
    void crea_giocatori();
    void match();
    void game_window();
    void crea_caselle();
    void crea_mazzo();
    void show_cards();
    int pesca();
    void cardAllBackDiversi(int j);
    void cardAllStillUguali(int j);
    void aggiungi_oggetto(Giocatore* g,int n);


    //General_functions.cpp
    bool vittoria(Giocatore* g);
    bool almeno_uno();
    int cerca_turno();
    void hai_vinto();

};



#endif // GOP_H
