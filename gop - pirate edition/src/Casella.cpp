//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#include "../include/Casella.h"
#include "../include/Giocatore.h"
#include "../include/GOP.h"
#include "../include/Auxiliary_functions.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

#define cinque 5
#define acapo 15

//COSTRUTTORE
Casella::Casella(int n)
{
    this->numero=n;
    //srand(time(NULL));
    this->effetto=rand()%35;   // numero randomico da 0 a 34
}

//ESECUZIONE DELLA CASELLA
bool Casella::grafica_casella(Giocatore* l_giocatori[], int j, int num_giocatori, int num_caselle)     //giocatore e posizione attuale
{
    //SE SEI A 20 ALLORA SEI SULLA TERRA
    int n=this->effetto;
    bool b=false;
    clear();
    uguale(140);
    space(65);
    cout<<"Casella "<<this->numero<<endl;
    uguale(140);
    if(n>=23 || n==8){ //Casella vuota
        int m=rand()%4;
        if(m==0){endl(acapo); space(63); cout<< "Ahoy Captain!"; endl(1); space(62); cout<<"[Nessun effetto]";}
        else if(m==1){endl(acapo); space(67); cout<<"Arrrh!"; endl(1); space(62); cout<<"[Nessun effetto]";}
        else if(m==2){endl(acapo); space(67); cout<<"Yarrrh!"; endl(1); space(62); cout<<"[Nessun effetto]";}
        else if(m==3){endl(acapo); space(67); cout<<"Arrrgh!"; endl(1); space(62); cout<<"[Nessun effetto]";}
    }
    else if(n>=20)//Tira ancora i dadi
        casDadi(l_giocatori, j);

    else if(n>=15)//Vai avanti di N caselle
        casForwardN(l_giocatori, j);

    else if(n>=14) { //Pesca una carta
        casCard(); b=true;
    }
    else if(n>=11)//Indietro di 5 passi
        casBack5(l_giocatori, j);

    else if(n>=9) //Fai 5 col dado per un’azione (action 5)
        casAction5(l_giocatori, j, b);

    else if(n==7) //Vai alla casella N
        casMoveToN(l_giocatori, j, num_caselle);

    else if(n>=5) //Resta fermo N turni
        casStill(l_giocatori,j);

    else if(n>=3)//Un giocatore va dall’altro
        casJoin(l_giocatori, j, num_giocatori);

    else if(n>=1) //Scambia la posizione con un altro giocatore
        casScambio(l_giocatori, j, num_giocatori);

    else    //ritorna al porto o alla spiaggia
        casOver(l_giocatori, j);

    return b;
}

//METODI =========================================================================================================

//TIRA ANCORA I DADI
void Casella::casDadi(Giocatore* l_giocatori[], int j){
    if(this->numero<20){
        endl(acapo); space(46);
        cout<<"Il vento di prua "<<(char)138<<" a tuo favore, avanti ciurma!"<<endl;
        space(60);cout<<"[Tira ancora i dadi]";
    }
    else{
        endl(acapo); space(50);
        cout<<"Dritti alla meta...e conquista la preda!";
        endl(1); space(60); cout<<"[Tira ancora i dadi]";
    }
    premi_invio();
    int dice = dado( l_giocatori[j], l_giocatori[j]->getPosizione() );
    int pos = l_giocatori[j] -> getPosizione();
    l_giocatori[j] -> setPosizione(pos+dice);
    clear();
}

//SPOSTATI DI -5/5 CASELLE
void Casella::casForwardN(Giocatore* l_giocatori[], int j){     //spostati di n caselle
    srand(time(NULL));
    int n=0;
    do{
        n=rand()%10-5;     //N da -5 a +5
    }while(n==0);
    if(this->numero<20){
        endl(acapo); space(43);
        cout<<"Scilla e Cariddi ti stanno inseguendo, fuggi sciocco!!";
        endl(1); space(57); cout<<"[Spostati di "<<n<<" caselle]";
    }
    else{
        endl(acapo); space(19);
        cout<<"Attento! Ti stai avvicinando alla base della marina britannica, cambia sentiero e spera per il meglio.";
        endl(1); space(57); cout<<"[Spostati di "<<n<<" caselle]";
    }
    int pos = l_giocatori[j] -> getPosizione();
    pos=pos+n;
    if(pos<1)l_giocatori[j]->setPosizione(0);
    else l_giocatori[j]->setPosizione(pos);
}

//PESCA UNA CARTA
void Casella::casCard() {
    if(this->numero<20){
        endl(acapo); space(36);
        cout<<"Hai fatto lo sgambetto al capitano, vai all"<<(char)39<<"asse e pesca una carta.";
        endl(1); space(61); cout<<"[Pesca una carta]";
    }
    else{
        endl(acapo); space(27);
        cout<<"Il sole caraibico vi sta dando alla testa, pesca una carta e spera nella buona sorte.";
        endl(1); space(61); cout<<"[Pesca una carta]";
    }

}

//TORNA INDIETRO DI CINQUE CASELLE
void Casella::casBack5(Giocatore* l_giocatori[], int j) {
    if(this->numero<=20){
        endl(acapo); space(30);
        cout<<"Per mille spincarde! La tua rotta era sbagliata. Inverti la rotta di 5 leghe...";
        endl(1); space(60); cout<<"[Indietro di 5 passi]";
    }
    else{
        endl(acapo); space(6);
        cout<<"Corpo di mille balene! Il troppo rum vi ha fatto perdere la retta via, torna indietro di 5 passi per trovare il giusto percorso.";
        endl(1); space(60); cout<<"[Indietro di 5 passi]";
    }
    int pos = l_giocatori[j] -> getPosizione();
    pos=pos-cinque;
    if(pos<1){
        pos=0;
    }
    l_giocatori[j] -> setPosizione(pos);
}

//FAI 5 PER RIMANERE FERMO ALTRIMENTI PESCA UNA CARTA
void Casella::casAction5(Giocatore* l_giocatori[], int j, bool &b){
    if(this->numero<20){
        endl(acapo); space(27);
        cout<<"In lontananza avvisti una tempesta, fai un 5 per evitarla, altrimenti pesca una carta.";
        endl(1); space(39); cout<<"[Fai 5 col dado per rimanere fermo altrimenti pesca una carta]";
    }
    else{
        endl(acapo); space(35);
        cout<<"Per mille bucanieri bucati, ti "<<(char)138<<" caduta la mappa nelle sabbie mobili."<<endl;
        space(35); cout<<"Fai un 5 per recuperarla, altrimenti sfida la sorte e pesca una carta.";
        endl(1); space(39); cout<<"[Fai 5 col dado per rimanere fermo altrimenti pesca una carta]";
    }
    premi_invio();
    int dice=dado(l_giocatori[j], l_giocatori[j]->getPosizione());
    if (dice != 5){ //pesca una carta
        b=true;
    }
    clear();
}

//PORTA IL GIOCATORE ALLA MEDIA TRA 20(OPP. MAX CASELLE) E LA SUA POSIZIONE
void Casella::casMoveToN(Giocatore* l_giocatori[], int j, int num_caselle){ //vai nella cas MEDIA
    if(this->numero<20){
        int n=(l_giocatori[j]->getPosizione()+20+2)/2;  //+2 per evitare caso speciale (20+20)/2 = 20
        l_giocatori[j] -> setPosizione(n);
        endl(acapo); space(32);
        cout<<"Notte di luna piena. Le stelle ti guidano sempre pi"<<(char)151<<" vicino alla meta.";
        endl(1); space(60); cout<<"[Vai alla casella "<<n<<"]";
    }
    else{
        int n=(l_giocatori[j]->getPosizione()+20+2)/2;
        l_giocatori[j] -> setPosizione(n);
        endl(acapo); space(20);
        cout<<"Hai trovato un sentiero riparato dal sole, decidi di intraprenderlo. Chiss"<<(char)133<<" se ti porter"<<(char)133<<" fortuna...";
        endl(1); space(60); cout<<"[Vai alla casella "<<n<<"]";
    }

}

//RESTA FERMO DUE TURNI
void Casella::casStill(Giocatore* l_giocatori[], int j) { //Resta fermo N turni
    int n=2;
    if(this->numero<20){
        endl(acapo); space(33);
        cout<<"Sirene! Ti hanno incantato con un canto melodioso e lunghi capelli dorati.";
        endl(1); space(60); cout<<"[Resta fermo "<<n<<" turni]";
    }
    else{
        endl(acapo); space(25);
        cout<<"Gli indigeni dell"<<(char)39<<"isola vi hanno catturato, prenditi del tempo per pianificare la tua fuga.";
        endl(1); space(60); cout<<"[Resta fermo "<<n<<" turni]";
    }
    l_giocatori[j] -> setGioca(n);
}

//UN GIOCATORE VA NELLA STESSA CASELLA DELL'ALTRO
void Casella::casJoin(Giocatore* l_giocatori[], int j, int num_giocatori) { //Un giocatore va dall’altro
    int n=0;
    do{
        n=rand()%num_giocatori;
    }while(n==j);
    int posizione_gioc = l_giocatori[n]->getPosizione();
    l_giocatori[j]-> setPosizione(posizione_gioc);

    if(this->numero<20){
        endl(acapo); space(38);
        cout<<"Bracciate il pennone sottospecie di mozzi! "<<(char)212<<" il momento della resa dei conti,"<<endl;
        space(43); cout<<"raggiungi il capitano "<<l_giocatori[n]->getNome()<<" e dimostra il tuo valore!";
        endl(1); space(53); cout<<"[Raggiungi "<<l_giocatori[n]->getNome()<<" alla posizione "<<l_giocatori[n]->getPosizione()<<"]";
    }
    else{
        endl(acapo); space(21);
        cout<<"Nella nebbia intravedi un"<<(char)39<<"altra ciurma, dopo averli raggiunti ti offrono del rum. Resta con loro.";
        endl(1); space(46); cout<<"[Raggiungi "<<l_giocatori[n]->getNome()<<" alla posizione "<<l_giocatori[n]->getPosizione()<<"]";
    }
}

//SCAMBIA DUE GIOCATORI
void Casella::casScambio(Giocatore* l_giocatori[], int j, int num_giocatori){
    srand(time(NULL));
    int n=0;
    do{
        n=rand()%num_giocatori;
    }while(n==j);
    int posizione_gioc = l_giocatori[n]->getPosizione();
    int pos2= l_giocatori[j]->getPosizione();
    l_giocatori[j]-> setPosizione(posizione_gioc);
    l_giocatori[n]-> setPosizione(pos2);
    if(this->numero<20){
        endl(acapo); space(26);
        cout<<"Dopo una veloce nuotata la tua ciurma "<<(char)138<<" salita accidentalmente sulla nave del capitano "<<l_giocatori[n]->getNome()<<"."<<endl;
        space(51); cout<<"Raggiungili e scambiatevi il vascello.";
        endl(1); space(49); cout<<"[Scambiati col giocatore alla posizione "<< posizione_gioc<<"]";
    }
    else{
        endl(acapo); space(51);
        cout<<"In lontananza vedi il fuoco di "<<l_giocatori[n]->getNome()<<"."<<endl;
        space(38); cout<<"Decidete entrambi di andare a controllare, scambiandovi i posti.";
        endl(1); space(49); cout<<"[Scambiati col giocatore alla posizione "<< posizione_gioc<<"]";
    }

}

//SE IL GIOCATORE E' SOTTO 20 ALLORA VA A ZERO, SE GIOCATORE SOPRA VENTI ALLORA VA A 20
void Casella::casOver(Giocatore* l_giocatori[], int j){
    int pos = l_giocatori[j] -> getPosizione();
    if(this->numero>=20){ //Torna all’inizio della zona isola
        endl(acapo); space(37);
        cout<<"CANNIBALI!!! La tua ciurma "<<(char)138<<" stata divorata da una trib"<<(char)151<<" indigena."<<endl;
        space(49); cout<<"Torna indietro e rifugiati sulla tua nave."<<endl;
        space(53); cout<<"[Torna alla spiaggia, casella 20]";
        l_giocatori[j] -> setPosizione(20);
    }
    else { //Torna all’inizio
        l_giocatori[j] -> setPosizione(0);
        endl(acapo); space(21);
        cout<<"MAELSTROM!!! Sei vivo per miracolo ma nave e ciurma sono state risucchiate nelle profodit"<<(char)133<<" marine."<<endl;
        space(47); cout<<"Torna al porto e ricomincia la tua avventura."<<endl;
        space(56); cout<<"[Torna al porto, casella 0]";
    }
}

//SETTERS AND GETTERS
void Casella::setEffetto(int effetto) {
    Casella::effetto = effetto;
}

//DISTRUTTORE
Casella::~Casella()
= default;



