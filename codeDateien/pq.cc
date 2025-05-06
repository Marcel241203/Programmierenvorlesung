#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double p, q;

    cout << "Test";
    std::cout << "Berechung der PQ-Formel" << std::endl;
    std::cout << "p eingeben:";

    std::cin >> p;

    std::cout << "q eingeben:";

    std::cin >> q;

    double D = p * p / 4 - q;

        if (D < 0)
    {
        std::cout << "Das Polynom x^2 + " << p << " x+ " << q << " hat keine Nullstellen" << std::endl;
    }
    else if (D == 0)
    {
        std::cout << "Das Polynom x^2 + " << p << " x+ " << q << " hat eine Nullstelle. Diese liegt bei " << -p / 2. << std::endl;
    }
    else
    {
        double x1 = -p / 2 + std::sqrt(D);
        double x2 = -p / 2 - std::sqrt(D);
        std::cout << "Das Polynom x^2 + " << p << " x+ " << q << " hat zwei Nullstellen. Diese liegen bei " << x1 << " und " << x2 << std::endl;
    }
    return 0;
}