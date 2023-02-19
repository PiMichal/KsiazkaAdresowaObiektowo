#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    int pobierzIdNowegoUzytkownika();
    vector <Uzytkownik> uzytkownicy;
    MetodyPomocnicze metodyPomocnicze;
    PlikZUzytkownikami plikZUzytkownikami;
    Uzytkownik podajDaneNowegoUzytkownika();


    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {

        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    int logowanieUzytkownika();

    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);


    void rejestracjaUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();


};

#endif
