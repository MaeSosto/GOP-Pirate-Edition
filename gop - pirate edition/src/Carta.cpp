//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#include "../include/Casella.h"
#include "../include/Giocatore.h"
#include "../include/Carta.h"
#include "../include/GOP.h"
#include "../include/Auxiliary_functions.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "conio.h"
#include "windows.h"

using namespace std;

Carta::Carta(int n, int m)
{
    this->numero=n;
    this->oggetto=m;
}

int Carta::getOggetto() const {
    return oggetto;
}

void Carta::setOggetto(int oggetto) {
    Carta::oggetto = oggetto;
}

/*
Carta::~Carta()
= default;
*/
Carta::~Carta()
{
    cout<<"il mazzo è stato distrutto";
    Sleep(5000);
}