#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class KsiazkaAdresowa
{

    UzytkownikMenedzer uzytkownikMenedzer;
    void wyswietlOpcjeZMenuGlownego();
    void wyswietlOpcjeZMenuUzytkownika();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    void wybierzOpcjeZMenuGlownego();
    void wybierzOpcjeZMenuUzytkownika();

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
};

#endif
