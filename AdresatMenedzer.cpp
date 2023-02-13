#include "AdresatMenedzer.h"

int AdresatMenedzer::dodajAdresata()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    Adresat adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    plikZadresatami.dopiszAdresataDoPliku(adresat);
    return plikZadresatami.pobierzIdOstatniegoAdresata();
}


Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId(plikZadresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(pobierzidZalogowanegoUzytkownika());

    cout << "Podaj imie: ";
    adresat.ustawImie(metodyPomocnicze.wczytajLinie());
    adresat.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(metodyPomocnicze.wczytajLinie());
    adresat.ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(metodyPomocnicze.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metodyPomocnicze.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(metodyPomocnicze.wczytajLinie());

    return adresat;
}

string AdresatMenedzer::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(){

    adresaci = plikZadresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(pobierzidZalogowanegoUzytkownika());
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");


    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int addresseeNumber = 0; addresseeNumber < (int) adresaci.size(); addresseeNumber++)
        {
            wyswietlDaneAdresata(addresseeNumber);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(int addresseeNumber)
{
    cout << endl << "Id:                 " << adresaci[addresseeNumber].pobierzId() << endl;
    cout << "Imie:               " << adresaci[addresseeNumber].pobierzImie() << endl;
    cout << "Nazwisko:           " << adresaci[addresseeNumber].pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresaci[addresseeNumber].pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresaci[addresseeNumber].pobierzEmail() << endl;
    cout << "Adres:              " << adresaci[addresseeNumber].pobierzAdres() << endl;
}

void AdresatMenedzer::clearVector(){

    adresaci.clear();
}

int AdresatMenedzer::pobierzidZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika){

    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}
