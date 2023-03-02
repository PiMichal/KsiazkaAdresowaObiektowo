#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZUzytkownikami :public PlikTekstowy
{

    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:

    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : PlikTekstowy(nazwaPlikuZUzytkownikami){};

    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);


};

#endif
