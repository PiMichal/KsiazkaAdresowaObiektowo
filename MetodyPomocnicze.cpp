#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::wczytajLinie()
{
    cin.sync();
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczbaTekst){

    int liczba = stoi(liczbaTekst);
    return liczba;

}

int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        cin.sync();
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
