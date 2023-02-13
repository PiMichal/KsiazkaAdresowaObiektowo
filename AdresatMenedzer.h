#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer{

    MetodyPomocnicze metodyPomocnicze;
    PlikZAdresatami plikZadresatami;
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(int i);

public:
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    int pobierzidZalogowanegoUzytkownika();
    void clearVector();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();

};


#endif
