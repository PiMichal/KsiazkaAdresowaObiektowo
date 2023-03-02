#include "PlikZAdresatami.h"

vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {

    Adresat adresat;
    vector <Adresat> adresaci;
    fstream plikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    plikTekstowy.open(pobierzNazwePliku(), ios::in);

    if (plikTekstowy.good() == true) {

        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {

                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        }

    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);

    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < (int) daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(MetodyPomocnicze::konwersjaStringNaInt(pojedynczaDanaAdresata));
                break;
            case 2:
                adresat.ustawIdUzytkownika(MetodyPomocnicze::konwersjaStringNaInt(pojedynczaDanaAdresata));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
        if (czyPlikJestPusty() == true) {
            plikTekstowy << liniaZDanymiAdresata << endl;
        } else {
            plikTekstowy << liniaZDanymiAdresata << endl;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {

    return idOstatniegoAdresata;

}

void PlikZAdresatami::edytujAdresataWPliku(Adresat adresat) {

    string line, idEdytowanegoAdresata, edytowanyAdresat;
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;

    edytowanyAdresat = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    idEdytowanegoAdresata = edytowanyAdresat.substr(0, edytowanyAdresat.find('|'));
    odczytywanyPlikTekstowy.open(pobierzNazwePliku(), ios::in);
    tymczasowyPlikTekstowy.open("temp.txt", ios::out);

    while(getline(odczytywanyPlikTekstowy,line)) {
        line.substr(0, line.find('|')) != idEdytowanegoAdresata ? tymczasowyPlikTekstowy << line << endl : tymczasowyPlikTekstowy << edytowanyAdresat << endl;
    }

    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();
    remove(pobierzNazwePliku().c_str());
    rename("temp.txt", pobierzNazwePliku().c_str());

}

void PlikZAdresatami::usunWybranaLinieWPliku(Adresat adresat) {

    string line, idUsuwanegoAdresata, usuwanyAdresat;
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    odczytywanyPlikTekstowy.open(pobierzNazwePliku(), ios::in);
    tymczasowyPlikTekstowy.open("temp.txt", ios::out);

    usuwanyAdresat = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    idUsuwanegoAdresata = usuwanyAdresat.substr(0, usuwanyAdresat.find('|'));

    while(getline(odczytywanyPlikTekstowy, line)) {
        if (line.substr(0, line.find('|')) != idUsuwanegoAdresata)
            tymczasowyPlikTekstowy << line << endl;
    }

    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();
    remove(pobierzNazwePliku().c_str());
    rename("temp.txt", pobierzNazwePliku().c_str());

}


