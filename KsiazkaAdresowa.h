#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "Adresat.h"
#include "PlikTekstowy.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    PlikTekstowy plikTekstowy;
    AdresatMenedzer *adresatMenadzer;

    void wyswietlOpcjeZMenuGlownego();
    void wyswietlOpcjeZMenuUzytkownika();
    void wybierzOpcjeZMenuUzytkownika();


public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), plikTekstowy(nazwaPlikuZAdresatami){
        adresatMenadzer = NULL;
    };


    ~KsiazkaAdresowa(){
        delete adresatMenadzer;
        adresatMenadzer = NULL;
    };

    void wybierzOpcjeZMenuGlownego();

};

#endif
