//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#include <iostream>
#include "../include/Auxiliary_functions.h"
#include "../include/Giocatore.h"
using namespace std;
#define line 16
#define tabs 15
#define s 13

//PRIMA RIGA IN ALTO
void top_1(int n){
    for(int i=0; i< n; i++)
        cout<<"______ ";
}

//SECONDA RIGA IN ALTO
void top_2(int j, int& p){
    for(int i=0; i<j; i++){
        if(p<10) //VEDE QUANTO SPAZIO LASCIARE A SECONDA DI QUANTE CIFRE HA IL NUMERO DELLA CASELLA
            cout<<"  "<<p<<"   |";
        else
            cout<<"  "<<p<<"  |";
        p++;
    }
}

//TERZA RIGA IN ALTO
void top_3(int j,Giocatore* l_giocatori[], int h, int u) {//  c, l_giocatori, num, u= num giocatori
    h = h - line;// FA RIPARTIRE IL COUNTER DELLE CASELLE
    for (int i = 0; i < j; i++) {
        int c = 0;
        for (int x = 0; x < u; x++) {//CONTROLLA SE IN OGNI POSIZIONE C'E UN GIOCATORE
            if (l_giocatori[x]->getPosizione() == h) {
                c = c + 1;
                cout << l_giocatori[x]->getPedina();
            }
        }
        while (c < 6) {//STAMPA SPAZI SE NON SONO PRESENTI DEI GIOCATORI
            cout << " ";
            c++;
        }
        cout << "|";
        h = h + 1;
    }
}

void top_3_2(int j,Giocatore* l_giocatori[], int h, int u){
    h = h - line;// FA RIPARTIRE IL COUNTER DELLE CASELLE
    for (int i = 0; i < j; i++) {
        int c = 0;
        for (int x = 0; x < u; x++) {//CONTROLLA SE IN OGNI POSIZIONE C'E UN GIOCATORE
            if (l_giocatori[x]->getPosizione() == h+6) {
                c = c + 1;
                cout << l_giocatori[x]->getPedina();
            }
        }
        while (c < 6) {//STAMPA SPAZI SE NON SONO PRESENTI DEI GIOCATORI
            cout << " ";
            c++;
        }
        cout << "|";
        h = h + 1;
    }
}

//QUARTA RIGA IN ALTO
void top_4(int j){
    for(int i=0; i<j; i++)
        cout<<"______|";
}

//CREA SPAZI BIANCHI LUNGHI QUANTO UNA CASELLA
void blank(int n){
    for(int i=0; i<n; i++)
        cout<<"       ";
}

//CASELLA SINGOLA DI DESTRA, PRIMA RIGA
void right_1(int n){
    cout<<"|  "<<n<<"  |";
    cout<<endl;
}

//CASELLA SINGOLA DI DESTRA, SECONDA RIGA, CONTROLLA SE SIANO PRESENTI GIOCATORI
void right_2(Giocatore* l_giocatori[], int h, int u){
    cout<<"|";
    int c=0;
    for (int x = 0; x < u; x++) {
        if (l_giocatori[x]->getPosizione() == h) {
            c = c + 1;
            cout << l_giocatori[x]->getPedina();
        }
    }
    while (c < 6) {
        cout <<" ";
        c++;
    }
    cout<<"|";
    cout<<endl;
}

//PRIMA RIGA IN BASSO
void bot_1(int n){
    //cout<<" ";
    for(int i=0; i< n; i++){
        if (i==n-1) //CONTROLLA DI COMBACIARE CON LA CASELLA SUPERIORE A DESTRA
            cout<<"|______|";
        else if (i==n-2)
            cout<<"______";
        else
            cout<<"______ ";
    }
    cout<<endl;
}

//SECONDA RIGA IN BASSO
void bot_2(int j, int& num){
    int p=num;
    for(int i=j; i>0; i--){
        cout<<"  "<<p+i<<"  |";
        num++;
    }
    cout<<endl;
}

//TERZA RIGA IN BASSO
void bot_3(int j,Giocatore* l_giocatori[], int h, int u){

    for(int i=0; i<j; i++) {
        int c=0;
        for (int x = 0; x < u; x++) {
            if (l_giocatori[x]->getPosizione() == h) {
                c = c + 1;
                cout << l_giocatori[x]->getPedina();
            }
        }
        while (c < 6) {
            cout << " ";
            c++;
        }
        cout<<"|";
        h=h-1;
    }
    cout<<endl;
}



//QUARTA RIGA IN BASSO
void bot_4(int j){
    for(int i=0; i<j; i++)
        cout<<"______|";
    cout<<endl;
}

//CASELLA SINGOLA DI SINISTRA, PRIMA RIGA
void left_1(int n){
    cout<<"|  "<<n<<"  |";
    cout<<endl;
}

//CASELLA SINGOLA DI SINISTRA, SECONDA RIGA. CONTROLLA SE SIANO PRESENTI GIOCATORI
void left_2(Giocatore* l_giocatori[],int h, int u){
    //h numero della casella
    //u numero dei giocatori presenti
    cout<<"|";
    int c=0;
    for (int x = 0; x < u; x++) {
        if (l_giocatori[x]->getPosizione() == h) {
            c = c + 1;
            cout << l_giocatori[x]->getPedina();
        }
    }
    while (c < 6) {
        cout <<" ";
        c++;
    }
    cout<<"|";
    cout<<endl;
}

//PRIMA RIGA IN ALTO QUANDO SI E' SOTTO UNA CASELLA SINGOLA DI SINISTRA
void top_1_1(int n){
    for(int i=0; i< n; i++){
        if (i==0)//CONTROLLA DI COMBACIARE CON LA CASELLA SINGOLA DI SINISTRA
            cout<<"|______|";
        else
            cout<<"______ ";
    }
}


//STAMPA IL TABELLONE (OTTIMALE TRA 35-65)
//pre-condition (n = num_caselle, u = num_giocatori, puntatore alla lista di giocatori)
void tabellone(int n, int u, Giocatore* l_giocatori[]){
    int c=n, num=0; //c TIENE IL CONTO DI QUANTE CASELLE MANCANO DA STAMPARE, NUM INVECE CONTA A CHE NUMERO DI CASELLA SIAMO ARRIVATI
    //STAMPA TUTTA LA PRIMA RIGA
    space(s+1); top_1(line);
    cout<<endl;
    space(s); cout<<"|";
    top_2(line, num); //num aumenta a 15
    cout<<endl;
    space(s); cout<<"|";
    top_3(line, l_giocatori, num, u);
    cout<<endl;
    space(s); cout<<"|";
    top_4(line);
    cout<<endl;

    //STAMPA NUMERO A DESTRA
    space(s); blank(tabs);
    right_1(num);
    space(s); blank(tabs);
    right_2(l_giocatori, num, u);

    //STAMPA RIGA IN BASSO
    space(s); cout<<" ";
    bot_1(line);
    space(s); cout<<"|";
    bot_2(line, num);
    space(s); cout<<"|";
    bot_3(line, l_giocatori, num, u);
    space(s); cout<<"|";
    bot_4(line);
    num++;

    //STAMPA NUMERO A SINISTRA
    space(s); left_1(num);
    space(s); left_2(l_giocatori, num, u);
    c=c-num;
    num++;
    if(c<17){ //CONTROLLA SE BISOGNA STAMPARE TUTTA LA RIGA O SOLO IN PARTE
        //STAMPA PARZIALMENTE LA RIGA
        space(s); top_1_1(c); //34->c=16 49->c=1
        cout<<"__  __"<<endl;
        space(s); cout<<"|";
        top_2(c,num);
        cout<<"\\ \\/ /"<<endl;
        space(s); cout<<"|";
        top_3_2(c, l_giocatori, num, u);
        cout<<" >  < "<<endl;
        space(s); cout<<"|";
        top_4(c);

        cout<<"/_/\\_\\"<<endl;
        c-=line;
    }
    else{
        //STAMPA TUTTA LA RIGA
        space(s); top_1_1(line);
        cout<<endl;
        space(s); cout<<"|";
        top_2(line,num);
        cout<<endl;
        space(s); cout<<"|";
        top_3(line, l_giocatori, num, u);
        cout<<endl;
        space(s); cout<<"|";
        top_4(line);
        cout<<endl;
        c-=line;
        if(c==0){
            //SE HA STAMPATO LA LUNGHEZZA TOTALE DEL TABELLONE VIENE AGGIUNTA LA X
            blank(tabs);
            cout<<"__  __"<<endl;
            blank(tabs);
            cout<<"\\ \\/ /"<<endl;
            blank(tabs);
            cout<<" >  < "<<endl;
            blank(tabs);
            cout<<"/_/\\_\\"<<endl;
        }
        if(c>0){
            //SE NON E' STATA RAGGIUNTA LA LUNGHEZZA DEL TABELLONE TOTALE ALLORA BISOGNA AGGIUNGERE DELLE CASELLE
            space(s); blank(tabs);
            right_1(num);
            space(s); blank(tabs);
            right_2(l_giocatori, num, u);
            c--;
            if(c==0){
                //SE IL TABELLONE E' LUNGO 50 LA X BISOGNA STAMPARLA AL DI SOTTO DELLA CASELLA
                space(s); blank(tabs);
                cout<<"|______|"<<endl;
                space(s); blank(tabs);
                cout<<" \\ \\/ /"<<endl;
                space(s); blank(tabs);
                cout<<"  >  < "<<endl;
                space(s); blank(tabs);
                cout<<" /_/\\_\\"<<endl;
            }
            if(c>0){
                //SE NON E' STATA RAGGIUNTA LA LUNGHEZZA DEL TABELLONE TOTALE ALLORA BISOGNA AGGIUNGERE DELLE CASELLE
                cout<<" ";
                space(s); blank(tabs-c);
                cout<<"__  __";
                if(c!=1)
                    cout<<" ";
                bot_1(c);
                blank(tabs-c);
                space(s); cout<<" \\ \\/ /"<<"|";
                bot_2(c, num);
                blank(tabs-c);
                space(s); cout<<"  >  < "<<"|";
                bot_3(c, l_giocatori, num, u);
                blank(tabs-c);
                space(s); cout<<" /_/\\_\\"<<"|";
                bot_4(c);
            }
        }
    }
}