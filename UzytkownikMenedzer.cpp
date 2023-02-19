#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    system("cls");
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        login = metodyPomocnicze.wczytajLinie();
        uzytkownik.ustawLogin(login);

    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    haslo = metodyPomocnicze.wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{

   for (int i = 0; i < (int) uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
   }
    return false;
}

int UzytkownikMenedzer::logowanieUzytkownika()
{
    system("cls");
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << "Podaj login: ";
    login = metodyPomocnicze.wczytajLinie();

    for (int i = 0; i < (int) uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metodyPomocnicze.wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    ustawIdZalogowanegoUzytkownika(uzytkownicy[i].pobierzId());
                    return pobierzIdZalogowanegoUzytkownika();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}


void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    Uzytkownik uzytkownik;
    system("cls");
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = metodyPomocnicze.wczytajLinie();

    for (int i = 0; i < (int) uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == pobierzIdZalogowanegoUzytkownika())
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}
void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika){
    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}
