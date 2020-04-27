//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#ifndef GIOCATORE_H
#define GIOCATORE_H

#define venti 20

static const int sette = 7;

#include <cstring>
#include <string>
#include "../include/GOP.h"

using namespace std;

class GOP;
class Casella;
class Carta;

class Giocatore
{
public:
    Giocatore(int n, int t, Giocatore* l_giocatori[]);
    virtual ~Giocatore();
    int conta_carte();
    bool card_tutti();
    int find(int n);
    int card_uguali();

    //SETTERS AND GETTERS
    void print_player();
    char getPedina() const;
    int getTurno() const;
    int getPosizione() const;
    void setPosizione(int posizione);
    int getGioca() const;
    void setGioca(int gioca);
    void getInventario();
    const char *getNome() const;
    void setInventario(int pos, int val);

    int getNumero() const;


private:
    //CAMPI
    char nome[venti];
    int numero;     //NUMERO DI INSERIMENTO GIOCATORI
    int turno;      //TURNO DEL GIOCATORE - ORDINE DI GIOCO
    char pedina;    //CARATTERE CHAR UTILIZZATO NELLA MAPPA
    int posizione;  //IN CHE CASELLA SEI
    int gioca;      //SALTI IL TURNO OPPURE NO
    int inventario[sette]; //inventario degli oggetti

    //METODI

    void inventario_zero();
    void rimuovi_1carta();
    void rimuovi_slot(int n);


};

#endif // GIOCATORE_H
