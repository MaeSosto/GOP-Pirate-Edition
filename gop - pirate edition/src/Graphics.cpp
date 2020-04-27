//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#include <conio.h>
#include <iostream>
#include <windows.h>
#include "../include/Auxiliary_functions.h"
#include "../include/GOP.h"
#include "../include/Giocatore.h"
#include "../include/Casella.h"
#define v 21
#define c 53
#define q 17
#define f 43
using namespace std;

//SCHERMATA GIOCO INIZIALE
void start_screen ()
{
    char p='~';
    while(p=='~'){
        clear();
        endl(5);
        space(v); cout<<" #####                                                                  ###                          "<<endl;
        space(v); cout<<"#     #  #   ####    ####    ####       #####   ######  #       #       ###   ####    ####     ##    "<<endl;
        space(v); cout<<"#        #  #    #  #    #  #    #      #    #  #       #       #        #   #    #  #    #   #  #   "<<endl;
        space(v); cout<<"#  ####  #  #    #  #       #    #      #    #  #####   #       #       #    #    #  #       #    #  "<<endl;
        space(v); cout<<"#     #  #  #    #  #       #    #      #    #  #       #       #            #    #  #       ######  "<<endl;
        space(v); cout<<"#     #  #  #    #  #    #  #    #      #    #  #       #       #            #    #  #    #  #    #  "<<endl;
        space(v); cout<<" #####   #   ####    ####    ####       #####   ######  ######  ######        ####    ####   #    #  "<<endl<<endl;
        space(c); cout<<"#####     ##    ######  ######    ##   "<<endl;
        space(c); cout<<"#    #   #  #       #       #    #  #  "<<endl;
        space(c); cout<<"#    #  #    #     #       #    #    # "<<endl;
        space(c); cout<<"#####   ######    #       #     ###### "<<endl;
        space(c); cout<<"#       #    #   #       #      #    # "<<endl;
        space(c); cout<<"#       #    #  ######  ######  #    # "<<endl;
        cout<<endl<<endl;
        space(q); cout<<  " __  __    ____    _                  _                         _   _   _     _                    __  __"<<endl;
        space(q); cout<< R"( \ \/ /   |  _ \  (_)  _ __    __ _  | |_    ___      ___    __| | (_) | |_  (_)   ___    _ __     \ \/ /)" <<endl;
        space(q); cout<< R"(  \  /    | |_) | | | | '__|  / _` | | __|  / _ \    / _ \  / _` | | | | __| | |  / _ \  | '_ \     \  /)" <<endl;
        space(q); cout<<  "  /  \\    |  __/  | | | |    | (_| | | |_  |  __/   |  __/ | (_| | | | | |_  | | | (_) | | | | |    /  \\"<<endl;
        space(q); cout<< R"( /_/\_\   |_|     |_| |_|     \__,_|  \__|  \___|    \___|  \__,_| |_|  \__| |_|  \___/  |_| |_|   /_/\_\)" << endl;
        endl(7); space(c); cout<<"Premi un tasto qualsiasi per continuare";

        p=(char) _getch();
    }
}

//SCHERMATA CON I CAPITANI
void capitani(){
    clear(); endl(3);
    space(f); cout<<  "   ____                   _   _                     _ "<<endl;
    space(f); cout<<  "  / ___|   __ _   _ __   (_) | |_    __ _   _ __   (_)"<<endl;
    space(f); cout<<  " | |      / _` | | '_ \\  | | | __|  / _` | | '_ \\  | |"<<endl;
    space(f); cout<<  " | |___  | (_| | | |_) | | | | |_  | (_| | | | | | | |"<<endl;
    space(f); cout<< R"(  \____|  \__,_| | .__/  |_|  \__|  \__,_| |_| |_| |_|)" <<endl;
    space(f); cout<<  "                 |_|                                  "<<endl<<endl;
}

//STAMPA UNA LINEA DI UGUALI
void uguale(int n){
    for(int i=0; i<n; i++) cout << "=";
}

//SCHERMATA DEL GIORNO ATTUALE
void mostra_giorno(int n){
    clear(); endl(7); space(66);
    cout<<"Giorno "<<n;
    endl(23); space(51);
    cout<<"Premi BARRA SPAZIATRICE per continuare";
    char p='~';
    do{
        p=(char) _getch();
    }while(p!=(char)32);    //32 spazio

}

//SCHERMATA FRASE INIZIO GIOCO
void bandiere(){
    clear(); endl(17); space(55);
    cout<<"Signori, issate le bandiere...";
    Sleep(5000);
}

//SCHERMATA FRASE FINE GIOCO
void frase(){
    clear(); endl(27); space(90);
    cout<<"Yo ho, yo ho a pirate's life for me";
    Sleep(5000);
}

//PARTE SOTTO LA MAPPA CHE FORNISC TUTTE LE INFORMAZIONI RIGUARDANTI IL SEGUENTE TURNO
void GOP::game_window(){
    clear(); uguale(140); space(66);
    cout<<"Giorno "<<this->round;
    space(48); cout<<"[ESC per uscire] ";
    endl(1); uguale(140);
    tabellone(this->num_caselle, this->num_giocatori, this->l_giocatori);
    int i=0; endl(1); uguale(140);
    cout<<endl<<" Capitani: "; space(83);
    cout<<"Nel mazzo rimangono "<<this->num_carte<<" carte - [TAB per info] "<<endl;

    while(i<this->num_giocatori){ //CONTATORE CHE DICE CHI DEVE GIOCARE (SE SEI AL PRIMO, SECONDO , TERZO TURNO)
        int j=0;
        while(j<this->num_giocatori){//CONTATORE CHE CONTROLLA QUALE GIOCATORE DEVE GIOCATORE DEVE GICARE AL TURNO i
            if(this->l_giocatori[j]->getTurno()==i+1) {
                if (this->l_giocatori[j]->getTurno() == this->next_turno)
                    cout << " -> ";
                else
                    cout << "    ";
                cout << "[ " << this->l_giocatori[j]->getPedina() << " ] " << this->l_giocatori[j]->getNome()
                     << " si trova nella casella " << this->l_giocatori[j]->getPosizione();
                if(this->l_giocatori[j]->getGioca()>0) cout<<" - Fermo per "<<this->l_giocatori[j]->getGioca()<<" turni.";
                cout<<endl;
            }
            j++;
        }
        i++;
    }
}

void carte_title(){

    clear(); endl(2);
    space(52); cout<<"   ____                  _          "<<endl;
    space(52); cout<<"  / ___|   __ _   _ __  | |_    ___ "<<endl;
    space(52); cout<<" | |      / _` | | '__| | __|  / _ \\"<<endl;
    space(52); cout<<" | |___  | (_| | | |    | |_  |  __/"<<endl;
    space(52); cout<< R"(  \____|  \__,_| |_|     \__|  \___|)" <<endl;
}

//GRAFICA CARTE
void pick_carta(int n){
    clear(); endl(7); space(64);
    cout<<"HAI TROVATO:";
    endl(5);

    if(n==1){//Rum
        space(57); cout<<" ____"; endl(1);
        space(57); cout<<"|  _ \\   _   _   _ __ ___"; endl(1);
        space(57); cout<<"| |_) | | | | | | '_ ` _  \\"; endl(1);
        space(57); cout<<"|  _ <  | |_| | | | | | | |"; endl(1);
        space(57); cout<<"|_| \\_\\  \\__,_| |_| |_| |_|"; endl(1);
    }
    else if(n==2) {//Polvere da sparo

        space(17); cout<<" ____            _                                      _                                                ";endl(1);
        space(17); cout<<"|  _ \\    ___   | | __   __   ___   _ __    ___      __| |   __ _     ___   _ __     __ _   _ __    ___  ";endl(1);
        space(17); cout<<"| |_) |  / _ \\  | | \\ \\ / /  / _ \\ | '__|  / _ \\    / _` |  / _` |   / __| | '_ \\   / _` | | '__|  / _ \\ ";endl(1);
        space(17); cout<<"|  __/  | (_) | | |  \\ V /  |  __/ | |    |  __/   | (_| | | (_| |   \\__ \\ | |_) | | (_| | | |    | (_) |";endl(1);
        space(17); cout<<"|_|      \\___/  |_|   \\_/    \\___| |_|     \\___|    \\__,_|  \\__,_|   |___/ | .__/   \\__,_| |_|     \\___/ ";endl(1);
        space(17); cout<<"                                                                           |_|                           ";endl(1);
    }

    else if(n==3){//Archibugio
        space(35); cout<<"    _                    _       _   _                       _         "; endl(1);
        space(35); cout<<"   / \\     _ __    ___  | |__   (_) | |__    _   _    __ _  (_)   ___  "; endl(1);
        space(35); cout<<"  / _ \\   | '__|  / __| | '_ \\  | | | '_ \\  | | | |  / _` | | |  / _ \\ "; endl(1);
        space(35); cout<<" / ___ \\  | |    | (__  | | | | | | | |_) | | |_| | | (_| | | | | (_) |"; endl(1);
        space(35); cout<<"/_/   \\_\\ |_|     \\___| |_| |_| |_| |_.__/   \\__,_|  \\__, | |_|  \\___/ "; endl(1);
        space(35); cout<<"                                                     |___/             "; endl(1);
    }
    else if(n==4){//Bussola
        space(46); cout<<" ____                                _         "; endl(1);
        space(46); cout<<"| __ )   _   _   ___   ___    ___   | |   __ _ "; endl(1);
        space(46); cout<<"|  _ \\  | | | | / __| / __|  / _ \\  | |  / _` |"; endl(1);
        space(46); cout<<"| |_) | | |_| | \\__ \\ \\__ \\ | (_) | | | | (_| |"; endl(1);
        space(46); cout<<"|____/   \\__,_| |___/ |___/  \\___/  |_|  \\__,_|"; endl(1);
    }
    else if(n==5){//Pappagallo
        space(34); cout<<" ____                                                    _   _         "; endl(1);
        space(34); cout<<"|  _ \\    __ _   _ __    _ __     __ _    __ _    __ _  | | | |   ___  "; endl(1);
        space(34); cout<<"| |_) |  / _` | | '_ \\  | '_ \\   / _` |  / _` |  / _` | | | | |  / _ \\ "; endl(1);
        space(34); cout<<"|  __/  | (_| | | |_) | | |_) | | (_| | | (_| | | (_| | | | | | | (_) |"; endl(1);
        space(34); cout<<"|_|      \\__,_| | .__/  | .__/   \\__,_|  \\__, |  \\__,_| |_| |_|  \\___/ "; endl(1);
        space(34); cout<<"                |_|     |_|              |___/                         "; endl(1);
    }
    else{//Doblone
        space(45); cout<<" ____            _       _                        "; endl(1);
        space(45); cout<<"|  _ \\    ___   | |__   | |   ___    _ __     ___ "; endl(1);
        space(45); cout<<"| | | |  / _ \\  | '_ \\  | |  / _ \\  | '_ \\   / _ \\"; endl(1);
        space(45); cout<<"| |_| | | (_) | | |_) | | | | (_) | | | | | |  __/"; endl(1);
        space(45); cout<<"|____/   \\___/  |_.__/  |_|  \\___/  |_| |_|  \\___|"; endl(1);
    }
    endl(10); space(51);
    cout<<"Premi BARRA SPAZIATRICE per continuare";
    char p='~';
    do{
        p=(char) _getch();
    }while(p!=(char)32);    //32 spazio
}


//OBBIETTIVO
void obiettivo(){
    clear(); endl(5); space(60);
    cout<<"~ SCOPO DEL GIOCO ~";
    endl(2); space(39); cout<<"Il primo capitano che taglier"<<(char)133<<" il traguardo sar"<<(char)133<<" il vincitore";

    endl(3); space(62); cout<<"~ SVOLGIMENTO ~";

    endl(2); space(20); cout<<"Ad ogni turno i capitani lanceranno i dadi sfidando la sorte e subiranno gli effetti delle caselle,";
    endl(1); space(52); cout<<"che siano questi positivi o negativi";

    endl(2); space(29); cout<<"Ci sar"<<(char)133<<" la possibilit"<<(char)133<<" di pescare carte e collezionare gli oggetti ivi raffigurati";

    endl(2); space(21); cout<<"Se saranno collezionati 6 oggetti DIVERSI fra loro, tutti i capitani retrocederanno di 3 caselle,";
    endl(1); space(44); cout<<"escluso il capitano in possesso delle suddette carte";

    endl(2); space(22); cout<<"Se saranno collezionati 6 oggetti UGUALI fra loro, tutti i capitani resteranno fermi di 1 turno,";
    endl(1); space(44); cout<<"escluso il capitano in possesso delle suddette carte";

    endl(2); space(37); cout<<"Questa "<<(char)133<<" una corsa contro il tempo alla ricerca del tesoro perduto";

    endl(2); space(22); cout<<"Alla partenza i capitani si troveranno nelle acque dell"<<(char)39<<"Oceano Atlantico, una volta superata la";
    endl(1); space(20); cout<<"casella numero 20, i capitani sbarcheranno sull"<<(char)39<<"isola del tesoro e dovranno lottare per raggiungere";
    endl(1); space(60); cout<<"il forziere nascosto";
    endl(6); space(51);
    cout<<"Premi BARRA SPAZIATRICE per continuare";
    char p='~';
    do{
        p=(char) _getch();
    }while(p!=(char)32);    //32 spazio
}

void graphicAllStillUguali(int n){
    clear(); endl(15);
    space(48); cout<<"Hurray, hai trovato 6 oggetti di tipo ";
    if(n==1)
        cout<<"Rum";
    else if(n==2)
        cout<<"Polvere da sparo";
    else if(n==3)
        cout<<"Archibugio";
    else if(n==4)
        cout<<"Bussola";
    else if(n==5)
        cout<<"Pappagallo";
    else
        cout<<"Doblone";
    cout<<"!"; //32 tot lettere
    endl(2); space(39); cout<<"Tuoni e fulmini, tutti i capitani si fermeranno di un turno.";
    endl(14); space(51); cout<<"Premi BARRA SPAZIATRICE per continuare";
    char p='~';
    do{
        p=(char) _getch();
    }while(p!=(char)32);    //32 spazio
}

void graphicAllBackDiversi(){
    clear(); endl(15);
    space(49); cout<<"Hurray, hai trovato tutti e 6 gli oggetti!";
    endl(2); space(29); cout<<"Il vento sta cambiando in tuo favore, tutti i capitani retrocederanno di 3 caselle.";
    endl(14); space(51); cout<<"Premi BARRA SPAZIATRICE per continuare";
    char p='~';
    do{
        p=(char) _getch();
    }while(p!=(char)32);    //32 spazio
}
