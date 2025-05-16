#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Gib eine Zahl ein, deren Spiegelzahl du wissen willst: ";
    cin >> n;

    int reversed = 0;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    cout << "Die Spiegelzahl von deiner Zahl ist " << reversed << endl;
    return 0;
}
