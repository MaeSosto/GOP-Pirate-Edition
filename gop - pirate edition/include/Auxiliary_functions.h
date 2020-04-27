//
// Created by Marti on 12/04/2018.
//

#ifndef TABELLONE_H_INCLUDED
#define TABELLONE_H_INCLUDED

#include "../include/Giocatore.h"
#include "../include/GOP.h"

class GOP;
class Giocatore;


//TABELLONE.CPP
void tabellone(int n, int u, Giocatore* l_giocatori[]);//(num caselle, num giocatori, lista giocatori)

//GENERAL_FUNCTIONS.CPP
int set_turn(int n, int v[]);
void set_vet(int v[], int n);
void clear();
void space(int n);
void endl(int n);
void tiro_dadi(Giocatore* g);
void premi_invio();
void uguale(int n);
void end(GOP g);
bool check_char(char s, Giocatore* l_giocatori[], int n);
bool check_name(char s[], Giocatore* l_giocatori[], int n);

//DADO.CPP
int dado(Giocatore* g, int c);

//GRAPHICS.CPP
void capitani();
void start_screen();
void mostra_giorno(int n);
void bandiere();
void frase();
void fermo(Giocatore* g);
void pick_carta(int n);
void carte_title();
void obiettivo();
void graphicAllBackDiversi();
void graphicAllStillUguali(int n);



#endif // TABELLONE_H_INCLUDED
