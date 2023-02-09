#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "PlikZUzytkownikami.h"


using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenadzer;
    void wyswietlOpcjeZMenuGlownego();
    void wybierzOpcjeZMenuUzytkownika();
    void wyswietlOpcjeZMenuUzytkownika();

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami){
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();

    };

    void wybierzOpcjeZMenuGlownego();



};

#endif
