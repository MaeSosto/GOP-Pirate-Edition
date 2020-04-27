//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#include "../include/Giocatore.h"
#include "../include/GOP.h"
#include "../include/Auxiliary_functions.h"
#include <cstring>
#include <iostream>
#include <conio.h>
#define grado 248
#define e 17
using namespace std;

Giocatore::Giocatore(int n, int t, Giocatore* l_giocatori[])
{//pre-condition: n numero giocatore
    //pre-condition: t numero turno di gioco settato con funz set_turn()
    this->numero=n;
    this->turno=t;
    this->posizione=0;
    this->gioca=0;
    this->inventario_zero();

    up:
    clear(); endl(e); space(42);
    cout<<n<<(char)grado<<"Capitano! Come vuoi essere chiamato dalla tua ciurma?"<<endl;
    space(42);
    int p=0, z=0;
    char h;
    bool b=false;

    do{
        restart:
        h=(char) _getch();
        if(h!=(char)13){
            if(h==(char)8) {
                p-=1;
                z-=1;
                this->nome[p] = '\0';
                clear(); endl(e); space(42);
                cout<<n<<(char)grado<<"Capitano! Come vuoi essere chiamato dalla tua ciurma?"<<endl;
                space(42);
                cout<<this->getNome();
                goto restart;
            }
            else {
                this->nome[p] = h;
                z = z + 1;
                cout << h;
            }
        }
        else
            b=true;
        p=p+1;
    }while(p<20 && !b);
    if(strlen(this->getNome())==0 || check_name(this->nome, l_giocatori, n))
        goto up;
    this->nome[z]='\0';
    char s[2]={'~','~'};
    this->pedina='~';
    do{
        clear(); endl(e); space(35);

        cout<<"Perfetto! Ora inserisci un carattere che ti rappresenter"<<(char)133<<" per i 7 mari"<<endl;
        space(70);

        cin>>s;

    }while(strlen(s)!=1 || check_char(s[0], l_giocatori, n));
    this->pedina=s[0];

}


//FUNZIONI CARTE =========================================================================================================


//CONTA TUTTE LE CARTE CHE HA UN GIOCATORE
int Giocatore::conta_carte(){
    int i=1, tot=0;
    while(i<7){
        tot = tot + this->inventario[i];
        i++;
    }
    return tot;
}

//AZZERA TUTTI GLI SLOT DELL'INVENTARIO DI UN GIOCATORE
void Giocatore::inventario_zero(){
    for(int i=0; i<7; i++){
        this->inventario[i]=0;
    }
}

//CONTROLLA CHE IL GIOCATORE ABBIA UNA CARTA SPECIFICA
int Giocatore::find(int n) {
    //pre-contition: n numero carta (da 1 a 6) che deve essere presente nell'inventario
    //post-cond: ritorna l'oggetto || ritorna 0
    if (this->inventario[n] > 0) return this->inventario[n];
    else return 0;
}

//CONTROLLO SE GIOCATORE HA TROVATO 6 OGGETTI UGUALI E IN CASO LI RIMUOVE
int Giocatore::card_uguali() {
    //pre-contition: n numero carta
    int b=0;
    for(int i=1; i<7; i++) {
        if (this->inventario[i] >= 6) {
            b = i;
        }
    }
    if(b>0){ //l'indice dell'oggetto dalla quale rimuovere 6 carte
        this->rimuovi_slot(b);
    }
    return b;
}

//CONTROLLO SE IL GIOCATORE HA TROVATO TUTTI E 6 GLI OGGETTI E IN CASO LI RIMUOVE
bool Giocatore::card_tutti(){
    //ritorna true se il gioc ha almeno una carta di ognuno
    //ritorna false se no
    bool m=true;
    int i=1;
    while(i<7 && m){
        if(this->inventario[i]==0) m=false;
        i++;
    }
    if (m==true){
        this->rimuovi_1carta();
    }

    return m;
}

//RIMUOVE UNA CARTE DI OGNI TIPO DAL GIOCATORE
void Giocatore::rimuovi_1carta(){
    for(int i=1;i<7;i++)
        this->inventario[i]=this->inventario[i]-1;
}

//RIMUOVE SEI CARTE DEL TIPO N DA UN GIOCATORE
void Giocatore::rimuovi_slot(int n){
    this->inventario[n]-=6;
}

//SETTERS AND GETTERS =========================================================================================================
void Giocatore::print_player(){
    cout<<"Il "<<this->numero<<(char)grado<<" capitano "<<this->nome<<" giocher"<<(char)133<<" per "<<this->turno<<(char)grado<<" usando la pedina: "<<this->pedina<<endl<<endl;
}

char Giocatore::getPedina() const {
    return pedina;
}

int Giocatore::getPosizione() const {
    return posizione;
}

const char *Giocatore::getNome() const {
    return nome;
}

int Giocatore::getTurno() const {
    return turno;
}

void Giocatore::setPosizione(int posizione) {
    this->posizione = posizione;
}

int Giocatore::getGioca() const {
    return gioca;
}

void Giocatore::setGioca(int gioca) {
    Giocatore::gioca = gioca;
}

//MOSTRA TUTTE LE COSE CHE HA UN GIOCATORE
void Giocatore::getInventario(){
    cout<<this->inventario[1]<<" Rum - "<<this->inventario[2]<<" Polvere da sparo - "<<this->inventario[3]<<" Archibugio - " <<this->inventario[4]<<" Bussola - "<<this->inventario[5]<<" Pappagallo - "<<this->inventario[6]<<" Doblone"<<endl;
}

void Giocatore::setInventario(int pos, int val){
    this->inventario[pos]=val;
}

int Giocatore::getNumero() const {
    return numero;
}

//DISTRUTTORE
Giocatore::~Giocatore() = default;