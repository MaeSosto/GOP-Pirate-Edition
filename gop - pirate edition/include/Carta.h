//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//
#include "../include/Auxiliary_functions.h"

#ifndef MAZZO_H
#define MAZZO_H

class Giocatore;
class Casella;
class GOP;

class Carta
{
public:
    Carta(int n,int m);
    virtual ~Carta();

    int getOggetto() const;

    void setOggetto(int oggetto);

protected:

private:
    int numero;
    int oggetto;
};

#endif