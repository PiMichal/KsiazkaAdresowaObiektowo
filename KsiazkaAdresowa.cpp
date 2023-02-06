#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {

    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {

    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();

}

void KsiazkaAdresowa::logowanieUzytkownika() {

    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::wyswietlOpcjeZMenuGlownego() {

    system("cls");
    cout << ">>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}

void KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    while (true) {
        KsiazkaAdresowa::wyswietlOpcjeZMenuGlownego();
        switch (getchar()) {
        case '1':
            uzytkownikMenedzer.rejestracjaUzytkownika();
            break;
        case '2':
            uzytkownikMenedzer.logowanieUzytkownika();
            if (uzytkownikMenedzer.idZalogowanegoUzytkownika > 0) {
                KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika();
            }
            break;
        case '9':
            exit(0);
            break;
/*        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break; */
        }
    }
}

void KsiazkaAdresowa::wyswietlOpcjeZMenuUzytkownika() {

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}


void KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {

    bool logOut = false;
    while(logOut == false) {
        KsiazkaAdresowa::wyswietlOpcjeZMenuUzytkownika();
        switch (getchar()) {
        case '1':
            //idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
            break;
        case '2':
            //wyszukajAdresatowPoImieniu(adresaci);
            break;
        case '3':
            //wyszukajAdresatowPoNazwisku(adresaci);
            break;
        case '4':
            //wyswietlWszystkichAdresatow(adresaci);
            break;
        case '5':
            //idUsunietegoAdresata = usunAdresata(adresaci);
            //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
            break;
        case '6':
            //edytujAdresata(adresaci);
            break;
        case '7':
            uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
            break;
        case '8':
            logOut = true;
            //adresaci.clear();
            break;
        }
    }
}
