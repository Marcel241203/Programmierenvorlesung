#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Spiegel eine Zahl, z.B. 123 -> 321
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

// Generiert ein boolesches Sieb bis maxN, sieb[i] == true <=> i ist prim
vector<bool> generatePrimeSieve(int maxN)
{
    vector<bool> is_prime(maxN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= maxN; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

void findAllPairsForN(int N)
{
    auto is_prime = generatePrimeSieve(N);

    // Liste der Primzahlen (1-basiert: prime_list[1] = 2)
    vector<int> prime_list;
    prime_list.push_back(0); // Platzhalter für Index 0
    for (int i = 2; i <= N; ++i)
    {
        if (is_prime[i])
        {
            prime_list.push_back(i);
        }
    }

    // Um schnell den Index einer Primzahl zu finden
    unordered_map<int, int> prime_to_index;
    for (size_t i = 1; i < prime_list.size(); ++i)
    {
        prime_to_index[prime_list[i]] = i;
    }

    unordered_set<int> used;

    for (size_t n = 1; n < prime_list.size(); ++n)
    {
        int p1 = prime_list[n];
        int p1_mirrored = mirror(p1);

        // Bedingungen: p1_mirrored muss prim sein
        if (p1_mirrored > N || !is_prime[p1_mirrored])
            continue;

        auto it = prime_to_index.find(p1_mirrored);
        if (it == prime_to_index.end())
            continue;

        int m = it->second;
        if (m >= n)
            continue;

        int mirrored_n = mirror(n);
        if (mirrored_n != m)
            continue;

        if (used.count(p1) || used.count(p1_mirrored))
            continue;

        used.insert(p1);
        used.insert(p1_mirrored);

        cout << p1 << " " << p1_mirrored << endl;
        cout << n << " " << m << endl;
        cout << "------------------------" << endl;
    }
}

int main()
{
    findAllPairsForN(100000000);
    return 0;
}
