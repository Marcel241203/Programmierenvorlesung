#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double pi = M_PI;

    double L = 0.;

    int n = 10000;

    double zaehler, nenner;

    cout << "pi =" << pi << "\n";

    double delta = 0.000001;

    int i = 0;

    while (abs(4 * L - pi) >= delta)
    {
        if (i % 2 == 0)
        {
            zaehler = 1.;
        }
        else
        {
            zaehler = -1.;
        }

        nenner = 2 * i + 1;

        L += zaehler / nenner;
        i++;
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         zaehler = 1.;
    //     }
    //     else
    //     {
    //         zaehler = -1.;
    //     }

    //     nenner = 2 * i + 1;

    //     L += zaehler / nenner;
    // }

    cout << "4*L =" << 4 * L << endl;
    cout << "Wir haben " << i << " Schritte benötigt";
}