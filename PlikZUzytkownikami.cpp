#include "PlikZUzytkownikami.h"

void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(pobierzNazwePliku(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika << endl;
        }
        else
        {
            plikTekstowy << liniaZDanymiUzytkownika << endl;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << pobierzNazwePliku() << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}

string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    fstream plikTekstowy;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    plikTekstowy.open(pobierzNazwePliku(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);

            uzytkownicy.push_back(uzytkownik);
        }

    }
    plikTekstowy.close();
    return uzytkownicy;
}

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < (int) daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:

                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}

void PlikZUzytkownikami::zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy)
{

    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(pobierzNazwePliku(), ios::out);
    if (plikTekstowy.good() == true)
    {
        for (int i = 0; i < (int) uzytkownicy.size(); i++)
        {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownicy[i]);

            plikTekstowy << liniaZDanymiUzytkownika << endl;

            liniaZDanymiUzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << pobierzNazwePliku() << endl;
    }
    plikTekstowy.close();
}
