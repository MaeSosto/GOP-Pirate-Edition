//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#include <ctime>
#include <cstring>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "../include/Auxiliary_functions.h"
using namespace std;

//CREA UN VETTORE PER IMPOSTARE I TURNI IN ORDINE
void set_vet(int v[], int n)
{
    int p=0;
    for(int i=0; i<n; i++){
        p=p+1;
        v[i]=p;
    }
}

//ASSEGNA I TURNI AI GIOCATORI TRAMITE IL VETTORE CREATO
int set_turn(int n, int v[])
{
    srand(time(0));
    int p, i = 0;
    bool b=false;
    do{
        p=rand()%n;
        if (v[p]!=0){
            b=true;
            i=v[p];
            v[p]=0;
        }
    }while(!b);
    return i;
}

//PULISCE LA SCHERMATA
void clear(){
    system("cls");
    SetConsoleTitle("[GOP - Pirate Edition]");
    system("mode con lines=35");//dimensione finestra prestabilito
    system("mode con cols=140");
}

//CREA SPAZI
void space(int n){
    for(int i=0; i<n; i++){
        cout<<" ";
    }
}

//STAMPA ENDL
void endl(int n){
    for(int i=0; i<n; i++){
        cout<<endl;
    }
}

//CHIEDE AL GIOCATORE DI PREMERE I DADI
void tiro_dadi(Giocatore* g){
    space(52);
    cout<<g->getNome()<<" "<<(char)138<<" il tuo turno, premi INVIO!";
}

//CHIEDE AL GIOCATORE DI PREMERE INVIO
void premi_invio(){
    char c='~';
    endl(15); space(57);
    cout<<"Premi INVIO per continuare";
    do{
        c=(char) _getch();
    }while(c!=(char)13);    //13 invio
}

//CONTROLLA CHE LA PEDINA NON SIA STATA GIA' PRESA
bool check_char(char s, Giocatore* l_giocatori[], int n){      //n=num_giocatori
    bool b = false;
    for(int i=0; i<n-1;i++){
        if(l_giocatori[i]->getPedina() == s){
            b=true;
        }
    }
    return b;
}

//CONTROLLA CHE IL NOME NON SIA GIA' STATO USATO
bool check_name(char s[], Giocatore* l_giocatori[], int n){      //n=num_giocatori
    bool b = false;
    for(int i=0; i<n-1;i++){
        if(strcmp(l_giocatori[i]->getNome(), s)==0){
            b=true;
        }
    }
    return b;
}

//RIFERISCE AL GIOCATORE CHE DEVE STARE FERMO
void fermo(Giocatore* g){
    clear(); endl(17); space(27);
    cout<<"Arrgh "<<g->getNome()<<" sei in stato di fermo, gli altri capitani avranno un bel vantaggio...";
}



