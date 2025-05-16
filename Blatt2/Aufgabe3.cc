#include <iostream>
using namespace std;

void findMinAndMaxofArrayWithLengthN(int n)
{
    double inputNumbers[n];
    cout << "Bitte geben Sie " << n << " Zahlen ein:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> inputNumbers[i];
    }

    int s = sizeof(inputNumbers) / sizeof(inputNumbers[0]);
    cout << "Das Maximum ist: " << *max_element(inputNumbers, inputNumbers + s) << endl;
    cout << "Das Mininum ist: " << *min_element(inputNumbers, inputNumbers + s) << endl;
}

int main()
{
    findMinAndMaxofArrayWithLengthN(5);
    return 0;
}
