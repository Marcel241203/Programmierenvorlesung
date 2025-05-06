#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    unsigned int i;
    cout << "Die wie vielste Primzahl willst du haben";

    cin >> i;
    unsigned int k = 0;
    unsigned int n = 2;
    unsigned int N = 20000;

    while (n < N && k < i)
    {

        unsigned int p = n;
        bool teilerGefunden = false;
        for (unsigned int i = 2; i < p; i++)
        {
            if (p % i == 0)
            {
                teilerGefunden = true;
                break;
            }
        }
        if (teilerGefunden)
        {
            cout << "Die Zahl " << p << " ist keine Primzahl \n";
        }
        else
        {

            cout << "Die Zahl " << p << " ist die " << k << "-te  Primzahl \n";
            k++;
        }
        n++;
    }
}