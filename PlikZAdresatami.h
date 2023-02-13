#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;


class PlikZAdresatami{

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int idOstatniegoAdresata;
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string nazwaPlikuZAdresatami;
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    bool czyPlikJestPusty();

public:
    PlikZAdresatami(){
    nazwaPlikuZAdresatami = "Adresaci.txt";
    };
    int pobierzIdOstatniegoAdresata();
    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);

};



#endif
