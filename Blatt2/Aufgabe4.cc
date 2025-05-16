#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int mirror(int n)
{
    int reversed = 0;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int PrimeIndex(int n)
{
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            count++;
    }
    return count;
}

void findAllPairsForN(int n)
{
    list<int> foundPrimes;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            int iMirrored = mirror(i);
            if (
                isPrime(iMirrored) && PrimeIndex(i) == mirror(PrimeIndex(iMirrored)) && PrimeIndex(i) > PrimeIndex(iMirrored) && !(find(foundPrimes.begin(), foundPrimes.end(), i) != foundPrimes.end()) && !(find(foundPrimes.begin(), foundPrimes.end(), iMirrored) != foundPrimes.end()))
            {
                foundPrimes.push_back(i);
                foundPrimes.push_back(iMirrored);

                cout << i << " " << iMirrored << endl;
                cout << PrimeIndex(i) << " " << PrimeIndex(iMirrored) << endl;
                cout << "------------------------" << endl;
            }
        }
    }
}

int main()
{
    findAllPairsForN(1000000);
    return 0;
}
