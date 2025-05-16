#include <iostream>
using namespace std;

unsigned int quersumme(unsigned int zahl)
{
    unsigned int summe = 0;
    while (zahl > 0)
    {
        summe += zahl % 10;
        zahl /= 10;
    }
    return summe;
}

int main()
{
    bool eingabeFortführen = true;

    while (eingabeFortführen)
    {
        unsigned int zahl;
        cout << "Bitte eine Zahl eingeben: ";
        cin >> zahl;

        if (zahl == 0)
        {
            cout << "Programm beendet." << endl;
            eingabeFortführen = false;
        }
        else
        {
            unsigned int summe = quersumme(zahl);
            cout << "Die Quersumme von " << zahl << " ist: " << summe << endl;
        }
    }
    return 0;
}
