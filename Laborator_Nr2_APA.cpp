#include <iostream>
#include <math.h>
#include<chrono>


using namespace std;
bool iSPrime(int n, int i);



void CirulErathostenie(int n) //ciurul lui Eratostene
{
    bool is_prime[9999999] = { 0 };

    for (int i = 2; i < n; i++)
        is_prime[i] = true;
    for (int i = 2; i < sqrt(n); i++)
    {

        if (is_prime[i] == true)
        {
            for (int j = i * i; j < n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    cout << "Numerele prime " << endl;

    for (int i = 1; i < n; i++)
    {
        if (is_prime[i] == true)
        {
            cout << i << " ";
        }
    }

}
void alg_iterativ(int n)
{
    int low = 0, i;
    bool isPrime = true;
    while (low < n)
    {

        isPrime = true;
        if (low == 0 || low == 1)
        {
            isPrime = false;
        }
        else
        {
            for (i = 2; i <= low / 2; ++i)
            {
                if (low % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }

        if (isPrime)
            cout << low << " ";

        ++low;
    }
}
void alg_recursiv(int n)
{
    for (int i = 0; i < n; i++) {
        if (iSPrime(i, 2)) {
            cout << i << " ";
        }
    }
}

bool iSPrime(int n, int i) {
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;

    return iSPrime(n, i + 1);
}



int main()
{
    int Number;
    cout << "Dati numarl n: ";
    cin >> Number;
    // PrimeNumber E;
    auto t1 = std::chrono::high_resolution_clock::now();
    cout << "Ciurul lui Erathostenie (formula) :" << endl;
    CirulErathostenie(Number);
    auto t2 = std::chrono::high_resolution_clock::now();
    cout << endl;
    long duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Time: " << duration << " microseconds" << endl;
    cout << endl;
    t1 = std::chrono::high_resolution_clock::now();
    cout << "Algoritmul iterativ :" << endl;
    alg_iterativ(Number);
    t2 = std::chrono::high_resolution_clock::now();
    cout << endl;
    duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Time: " << duration << " microseconds" << endl;
    cout << endl;
    t1 = std::chrono::high_resolution_clock::now();
    cout << "Algoritmul recursiv :" << endl;
    alg_recursiv(Number);
    t2 = std::chrono::high_resolution_clock::now();
    cout << endl;
    duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Time: " << duration << " microseconds" << endl;

    return 0;
}
