//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "../include/Giocatore.h"
#include "../include/Casella.h"
#include "../include/Carta.h"
#include "../include/GOP.h"
#define grado 248
#define e 17
#define quarantadue 42


using namespace std;

//COSTRUTTORE DEL GIOCO
GOP::GOP()
{
    srand(time(0));
    this->num_caselle=rand()%31+35; // MIN CASELLE 35 - MAX CASELLE 65  (estrae da 0 a 30, poi ci somma 35)
    this->num_carte=quarantadue;
    this->crea_caselle();
    this->round=1;
    this->next_turno=1;
    start_screen();
    this->set_players();
    this->crea_mazzo();
    this->crea_giocatori();
    this->show_players();
}



//SETTAGGI INIZIALI =========================================================================================================

//FUNZIONE CHE CHIEDE ALL'UTENTE QUANTI GIOCATORI PARTECIPERANNO
void GOP::set_players()
{
    char n='0';
    do{
        clear(); endl(e); space(44);
        cout<<"Quanti di voi partiranno per questa avventura? [2-6]"<<endl;
        space(70);
        cin>>n;
    }
    while(n<'2' || n>'6');
    this->num_giocatori=(int)n-'0'; //TRASFORMO DA CHAR A INT
}

//FUNZIONE CHE SETTA LE INFORMAZIONI SUI GIOCATORI
void GOP::crea_giocatori()
{
    int num_turn[this->num_giocatori];
    set_vet(num_turn, this->num_giocatori);
    for(int i=0; i<this->num_giocatori; i++){
        int n=set_turn(this->num_giocatori, num_turn);
        this->l_giocatori[i]=new Giocatore(i+1, n, this->l_giocatori);
    }
}

//ASSEGNA OGGETTI CASELLE RANDOM AL VETTORE l_caselle
void GOP::crea_caselle() {
    for(int i=0; i<=this->num_caselle; i++){
        this->l_caselle[i]=new Casella(i);      //post-condition = gli passa il "numero" della casella partendo da 0
    }
    this->l_caselle[0] -> setEffetto(23);   //controllo che la casella 0 di partenza non abbia nessun effetto
}


//FUNZIONE CHE TI MOSTRA L'ELENCO DEI GIOCATORI E TI PERMETTE DI INZIARE A GIOCARE
void GOP::show_players()
{
    capitani();
    for(int j=0; j<this->num_giocatori; j++){
        space(43);
        l_giocatori[j]->print_player();
    }
    endl(15); space(26);
    cout<<"Premi INVIO per spiegare le vele, BACKSPACE per resettare i capitani o EXIT per uscire dal gioco";
    //per restare a Tortuga e brindare in allegria--per ritornare alla taverna ????
    char c;
    do{
        c=(char) _getch();
    }while(c!=(char)13 && c!=(char)8 && c!=(char)27);
    if(c==(char)8){ //8 BACKSPACE
        this->set_players();
        this->crea_giocatori();
        this->show_players();
    }
    else if(c==(char)27){ //27 ESC

    }
    else if(c==(char)13){ //13 INVIO
        this->match();
    }
}


//TURNO =========================================================================================================

//FUNZIONE CHE FA ESEGUIRE IL TURNO (inteso come tutti i giocatori hanno giocato, allora +1)
void GOP::match(){
    int t=0, pos=0;
    char c='~';
    obiettivo();
    bandiere();
    mostra_giorno(this->next_turno);
    while( !almeno_uno()){
        map:
        this->game_window();        //il turno si svolge
        t=cerca_turno();
        tiro_dadi(l_giocatori[t]);
        do{
            c=(char) _getch();
        }while(c!=(char)13 && c!=(char)9 && c!=(char)27);

        if(c==(char)9){
            show_cards();
            goto map;
        }

        else if(c==(char)27){
            goto end;
        }

        //CONTROLLA SE IL GIOCATORE E' FERMO O PUO' GIOCARE
        if(this->l_giocatori[t]->getGioca()>0) {
            int v = this->l_giocatori[t]->getGioca();
            this->l_giocatori[t]->setGioca(v-1);
            fermo(this->l_giocatori[t]);
            premi_invio();
        }
        else {
            pos = this->l_giocatori[t]->getPosizione();
            l_giocatori[t]->setPosizione(pos + dado( l_giocatori[t],pos) );

            //CONTROLLA SE IL GIOCATORE E' SBARCATO SYLL'ISOLA
            if (pos < 20 && this->l_giocatori[t]->getPosizione() >= 20) {
                clear(); endl(17); space(56);
                cout << this->l_giocatori[t]->getNome() << " benvenuto sull" << (char) 39 << "isola.";
                premi_invio();
            }

            //SE TIRANDO I DADI IL GIOCATORE NON HA VINTO ALLORA
            if( !vittoria(l_giocatori[t])){
                pos = this->l_giocatori[t]->getPosizione();
                bool b=this->l_caselle[pos]->grafica_casella(this->l_giocatori, t, this->num_giocatori, this->num_caselle);
                premi_invio();
                if(b==true){
                    int p=pesca();
                    aggiungi_oggetto(l_giocatori[t],p); //PESCA UNA CARTA, INCREMENTA E VEDI SE RIESCE A FARE COMBO
                }

                int p=pesca();
                aggiungi_oggetto(l_giocatori[t],p); //PESCA UNA CARTA, INCREMENTA E VEDI SE RIESCE A FARE COMBO

                if(vittoria(l_giocatori[t])){
                   hai_vinto();
                   goto miao;
               }
            }
        }

        //SE IL GIOCATORE NON HA VINTO ALLORA IL TURNO VIENE INCREMENTATO

        if (this->next_turno < this->num_giocatori)
            this->next_turno += 1;
        else {
            this->next_turno = 1;
            this->round += 1;
            mostra_giorno(this->round);

        }
    }
    hai_vinto();
    goto miao;

    end:
    clear(); endl(17); space(62);
    cout<<"Sei sicuro?? :cc "<<endl;
    space(37); cout<<"[premi INVIO per tornare riprendere l"<<(char)39<<"avventura o ESC per uscire]";
    c='~';
    do{
        c=(char) _getch();
    }while(c!=(char)13 && c!=(char)27);
    if(c==(char)13)
        goto map;

    miao:
    clear();
}


//FUNZIONI CARTE=========================================================================================================

//AGGIUNGE UN OGGETTO N NELL'INVENTARIO
void GOP::aggiungi_oggetto(Giocatore* g,int n) {
    g->setInventario(n, g->find(n)+1);
    pick_carta(n);

    bool b=g->card_tutti();

    if(b==true){
        cardAllBackDiversi(g->getNumero());
        graphicAllBackDiversi();
    }

    int m=g->card_uguali();
    if(m>0){
        cardAllStillUguali(g->getNumero());
        graphicAllStillUguali(m);

    }
}


void GOP::show_cards(){

    carte_title();
    endl(2); space(55); cout<<"Nel mazzo rimangono "<<this->num_carte<<" carte.";

    for(int i=0; i< this->num_giocatori; i++){
        endl(2); space(60); cout<<this->l_giocatori[i]->getNome()<<" ha "<<this->l_giocatori[i]->conta_carte()<<" carte"<<endl;
        space(30); this->l_giocatori[i]->getInventario();
    }
    endl(2); space(48);
    cout<<"premi TAB per chiudere il men"<<(char) 151<<" delle caselle";
    char c='~';
    do{
        c=(char) _getch();
    }while(c!=(char)9);
}

//CREA UN ARRAY DI 42 CARTE, 6 RIPETIZIONI PER OGNI CARTA
void GOP::crea_mazzo() {
    int mazzo_tmp[quarantadue];
    int x = 0, i = 0, m = 1, n=0;
    while (m < 7) {
        x = x + 7;
        while (i < x) {
            mazzo_tmp[i] = m;
            i++;
        }
        m++;
    }
    for (int i = 1; i < quarantadue; i++) {
        n = rand() % quarantadue;
        while (mazzo_tmp[n] == 0) {
            n = rand() % quarantadue;
        }

        this->mazzo[i] = new Carta(i, mazzo_tmp[n]);
        mazzo_tmp[n] = 0;
    }
}


//PESCA UNA CARTA DAL MAZZO E TI RITORNA IL NUMERO DELL'OGGETTO PESCATO
int GOP::pesca(){
    int m=0, i=0;
    i = rand()%quarantadue;   //da 0 a 41 indice del mazzo
    m = this->mazzo[i]->getOggetto();
    num_carte = num_carte-1;
    if(this->num_carte==0){
        this->num_carte = quarantadue;
    }
    return m;
    /*
    int m;
    do {
        m = this->mazzo[num_carte-1]->getOggetto();
    }while(m==0);

    int n=m;
    this->mazzo[num_carte-1]->setOggetto(0);
    num_carte = num_carte - 1;*/
}



//6 di tipi diversi di carte -> tutti indietro di 3
void GOP::cardAllBackDiversi(int j){           //HOLLABACK GUUUUUUUUUUURL
    //pre-condition: j indice del gioc che ha le carte tutte giuste much nice, very ok
    for(int i=0; i<=this->num_giocatori; i++){
        if(i != j-1){
            int pos=this->l_giocatori[i]->getPosizione();
            if(pos-3<1)
                this->l_giocatori[i]->setPosizione(0);
            else
                this->l_giocatori[i]->setPosizione(pos-3);
        }
    }
}

//6 tutte di un tipo -> tutti fermi di un turno tranne te TRANNE TE TRANNE TEEEEEEEEE
void GOP::cardAllStillUguali(int j){
    //pre-condition: j indice del gioc che ha le carte tutte giuste much nice, very ok
    for(int i=0; i<=this->num_giocatori; i++){
        if(i != j-1){
            int gioca=this->l_giocatori[i]->getGioca();
            this->l_giocatori[i]->setGioca(gioca+1);
        }
    }
}

//FUNZIONI GENERALI=========================================================================================================

//CONTROLLA SE UN GIOCATORE SPECIFICO HA VINTO
bool GOP::vittoria(Giocatore* g){   //true se ha vinto - false se non ha vinto 1 giocatore
    bool b=false;
    if(g->getPosizione() > this->num_caselle)
        b=true;
    return b;
}

//CONTROLLA SE ALMENO UN GIOCATORE HA VINTO
bool GOP::almeno_uno(){
    bool b=false;
    int i=0;
    while(i<this->num_giocatori){
        if(this->l_giocatori[i]->getPosizione() > this->num_caselle) b=true;
        i++;
    }
    return b;
}

//CERCA CHI E' IL PROSSIMO GIOCATORE CHE DEVE GIOCARE
int GOP::cerca_turno(){//restituisce l'indice del puntatore (dentro al vettore) che punta al giocatore che deve giocare
    int i=0, n=0;
    while(i<this->num_giocatori){
        if(this->l_giocatori[i]->getTurno() == this->next_turno) n=i;
        i++;
    }
    return n;
}

//SI CONGRATULA CON IL VINCITORE
void GOP::hai_vinto(){
    int i=0, n=0;
    while(i<this->num_giocatori ){
        if( vittoria(l_giocatori[i]) ){
            n=i;
        }
        i++;
    }
    clear();
    endl(17); space(47);
    cout<<"Complimenti "<<this->l_giocatori[n]->getNome()<<", hai vinto la partita!!";
    premi_invio();
}


//SETTERS AND GETTERS=========================================================================================================
Giocatore *const *GOP::getL_giocatori() const {
    return l_giocatori;
}


//DISTRUTTORE=========================================================================================================
GOP::~GOP()
{
    frase();
    Sleep(5000);
}

