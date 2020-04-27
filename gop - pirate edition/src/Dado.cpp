//
// Created by Martina Sosto, Andrea Vicenzi e Sara Vorabbi - GOP Project - 2017/2018
//

#include <windows.h>
#include <ctime>
#include <conio.h>
#include <iostream>
#include "../include/Auxiliary_functions.h"
using namespace std;

#define s1 64
#define s2 60

//GRAFICA NUMERI DEL DADO
void numeri(int n) {
    clear();
    endl(8);
    if (n == 1) {
        space(s1); cout << "  1111111" << endl;
        space(s1); cout << " 1::::::1" << endl;
        space(s1); cout << "1:::::::1" << endl;
        space(s1); cout << "111:::::1" << endl;
        space(s1); cout << "   1::::1" << endl;
        space(s1); cout << "   1::::1" << endl;
        space(s1); cout << "   1::::1" << endl;
        space(s1); cout << "   1::::l" << endl;
        space(s1); cout << "   1::::l" << endl;
        space(s1); cout << "   1::::l" << endl;
        space(s1); cout << "   1::::l" << endl;
        space(s1); cout << "   1::::l" << endl;
        space(s1); cout << "111::::::111" << endl;
        space(s1); cout << "1::::::::::1" << endl;
        space(s1); cout << "1::::::::::1" << endl;
        space(s1); cout << "111111111111" << endl;
    } else if (n == 2) {
        space(s2); cout << " 222222222222222" << endl;
        space(s2); cout << "2:::::::::::::::22" << endl;
        space(s2); cout << "2::::::222222:::::2" << endl;
        space(s2); cout << "2222222     2:::::2" << endl;
        space(s2); cout << "            2:::::2" << endl;
        space(s2); cout << "            2:::::2" << endl;
        space(s2); cout << "         2222::::2" << endl;
        space(s2); cout << "    22222::::::22" << endl;
        space(s2); cout << "  22::::::::222 " << endl;
        space(s2); cout << " 2:::::22222" << endl;
        space(s2); cout << "2:::::2" << endl;
        space(s2); cout << "2:::::2" << endl;
        space(s2); cout << "2:::::2       222222" << endl;
        space(s2); cout << "2::::::2222222:::::2" << endl;
        space(s2); cout << "2::::::::::::::::::2" << endl;
        space(s2); cout << "22222222222222222222" << endl;
        //20 50
    } else if (n == 3) {
        space(s2); cout << " 3333333333333333" << endl;
        space(s2); cout << "3::::::::::::::::33" << endl;
        space(s2); cout << "3::::::33333:::::::3" << endl;
        space(s2); cout << "3333333     3::::::3" << endl;
        space(s2); cout << "            3::::::3" << endl;
        space(s2); cout << "            3::::::3" << endl;
        space(s2); cout << "    33333333::::::3" << endl;
        space(s2); cout << "    3::::::::::::3" << endl;
        space(s2); cout << "    33333333::::::3" << endl;
        space(s2); cout << "            3::::::3" << endl;
        space(s2); cout << "            3::::::3" << endl;
        space(s2); cout << "            3::::::3" << endl;
        space(s2); cout << "3333333     3::::::3" << endl;
        space(s2); cout << "3::::::33333:::::::3" << endl;
        space(s2); cout << "3::::::::::::::::33" << endl;
        space(s2); cout << " 3333333333333333" << endl;
        //20
    } else if (n == 4) {
        space(s2); cout << "       44444444444" << endl;
        space(s2); cout << "      4::::::::::4" << endl;
        space(s2); cout << "     4:::::::::::4" << endl;
        space(s2); cout << "    4:::::44:::::4" << endl;
        space(s2); cout << "   4:::::4 4:::::4" << endl;
        space(s2); cout << "  4:::::4  4:::::4" << endl;
        space(s2); cout << " 4:::::4   4:::::4" << endl;
        space(s2); cout << "4:::::444444:::::444" << endl;
        space(s2); cout << "4::::::::::::::::::4" << endl;
        space(s2); cout << "44444444444::::::444" << endl;
        space(s2); cout << "           4:::::4" << endl;
        space(s2); cout << "           4:::::4" << endl;
        space(s2); cout << "           4:::::4" << endl;
        space(s2); cout << "         44:::::::44" << endl;
        space(s2); cout << "         4:::::::::4" << endl;
        space(s2); cout << "         44444444444" << endl;
    } else if (n == 5) {
        space(s2); cout << "55555555555555555555" << endl;
        space(s2); cout << "5::::::::::::::::::5" << endl;
        space(s2); cout << "5::::::::::::::::::5" << endl;
        space(s2); cout << "5::::::5555555555555" << endl;
        space(s2); cout << "5::::::5" << endl;
        space(s2); cout << "5::::::5" << endl;
        space(s2); cout << "5::::::5555555555" << endl;
        space(s2); cout << "5:::::::::::::::::5 " << endl;
        space(s2); cout << "5555555555555::::::5" << endl;
        space(s2); cout << "             5::::::5" << endl;
        space(s2); cout << "             5::::::5" << endl;
        space(s2); cout << "55555555     5::::::5" << endl;
        space(s2); cout << "5:::::::55555::::::5" << endl;
        space(s2); cout << " 55::::::::::::::55" << endl;
        space(s2); cout << "   55::::::::::55" << endl;
        space(s2); cout << "     5555555555" << endl;
    } else if (n == 6) {
        space(s2); cout << "         66666666" << endl;
        space(s2); cout << "        6::::::6" << endl;
        space(s2); cout << "       6::::::6" << endl;
        space(s2); cout << "     6::::::6" << endl;
        space(s2); cout << "    6::::::6" << endl;
        space(s2); cout << "   6::::::6" << endl;
        space(s2); cout << "  6::::::6" << endl;
        space(s2); cout << " 6::::::::666666" << endl;
        space(s2); cout << "6:::::::::::::::66" << endl;
        space(s2); cout << "6::::::666666:::::6" << endl;
        space(s2); cout << "6:::::6      6:::::6" << endl;
        space(s2); cout << "6:::::6      6:::::6" << endl;
        space(s2); cout << "6::::::666666::::::6" << endl;
        space(s2); cout << " 66::::::::::::::66" << endl;
        space(s2); cout << "   66::::::::::66" << endl;
        space(s2); cout << "     6666666666" << endl;
    }
}

//FUNZIONE DEL DADO
int dado(Giocatore* g, int c)
{
    int n = 0;
    char p='~';
    do{
        clear();
        endl(17); space(54);
        cout<<g->getNome()<<" premi INVIO per tirare il dado!";
        p=(char) _getch();
    }while(p!=(char)13);

    srand(time(NULL));

    for(int i=0; i<10; i++){
        n = rand()%6+1;
        numeri(n);
        Sleep(75);
    }

    p='~';
    //PREMI INVIO PER RIPRENDERE IL GIOCO
    do{
        numeri(n);
        endl(8);
        space(55);
        if(c<20) cout<<"Capitano, avanza di "<<n<<" leghe!!!";
        else cout<<"Capitano, avanza di "<<n<<" passi!!!";
        endl(1); space(56); cout<<"[Premi INVIO per continuare]";
        p=(char) _getch();
    }while(p!=(char)13);
    return n;
}
