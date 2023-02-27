#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "Adresat.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenadzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

    void wyswietlOpcjeZMenuGlownego();
    void wybierzOpcjeZMenuUzytkownika();
    void wyswietlOpcjeZMenuUzytkownika();

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){
        adresatMenadzer = NULL;
    };

    ~KsiazkaAdresowa(){
        delete adresatMenadzer;
        adresatMenadzer = NULL;
    };

    void wybierzOpcjeZMenuGlownego();

};

#endif
