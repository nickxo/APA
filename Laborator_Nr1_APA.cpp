#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <math.h>
using namespace std;
clock_t t_it, t_rec, t_mat, start;

unsigned long long mat_rep = 0;// initializarea contoarelor
unsigned long long it_rep = 0;
unsigned long long rec_rep = 0;

void multiply(int F[2][2], int M[2][2]);// functie prototip

void power(int F[2][2], int n);// functie pentru matrice

unsigned long long Fibo_Matrix(int n);// functia matrice

unsigned long long int Fibo_Iterativ (int n)// functia iterativa
{
    int i = 0;// primele 2 elemente din sirul lui fibonaci
    int j = 1;
    for (int k = 1; k < n; k++)
        {
            int t;
            t = i + j;
            i = j;
            j = t;
            it_rep++;
        }
	return j;

};

unsigned long long int Fibo_Recursiv(int n)// algoritmul recursiv
{
    if (n <= 2)// calcul
        {
            return 1;
        }
    rec_rep++;//nr de repetari, incrementarea contorului
    return Fibo_Recursiv(n-2) + Fibo_Recursiv(n-1);
};

unsigned long long Fibo_Matrix(int n)
{
  int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
      return 0;
  power(F, n-1);

  return F[0][0];
}

int main()
{
	int n;
	short option;
	unsigned long long fib_num;
    cout << "1. Iterativa. \n2. Recursiva. \n3. Matrice. \n4. Exit. \n";
    cout << "n=  ";
    cin >> n;
    cout<<"----------------------------------------------------------------"<<endl;
    do{
    cout << "Alegeti metoda dorita: ";
    cin >> option;
    switch(option)
    {
        case 1 :
            {
                start = clock();
                fib_num = Fibo_Iterativ(n);
                t_it = clock()-start;
                cout<<"Numarul de pe pozitia "<<n<<" este "<<fib_num<<endl;
                cout<<"Timpul de executie: "<<(float)t_it/CLOCKS_PER_SEC<<" sec"<<endl;
                cout<<"Numarul de iteratii: "<<it_rep<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                break;
            }
        case 2 :
            {
                start = clock();
                fib_num = Fibo_Recursiv(n);
                t_rec = clock()-start;
                cout<<"Numarul de pe pozitia "<<n<<" este "<<fib_num<<endl;
                cout<<"Timpul de executie: "<<(float)t_rec/CLOCKS_PER_SEC<<" sec"<<endl;
                cout<<"Numarul de iteratii: "<<rec_rep<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                break;
            }
        case 3 :
            {
                start = clock();
                fib_num = Fibo_Matrix(n);
                t_mat = clock()-start;
                cout<<"Numarul de pe pozitia "<<n<<" este "<<fib_num<<endl;
                cout<<"Timpul de executie: "<<(float)t_mat/CLOCKS_PER_SEC<<" sec"<<endl;
                cout<<"Numarul de iteratii: "<<mat_rep<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                break;
            }
        case 4 :
            {
                cout<<"Iesire din program..."<<endl;
                exit(1);
            }
    }
    }
    while(option!=4);
	return 0;
}

void multiply(int F[2][2], int M[2][2])
{
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
  mat_rep++;
}

void power(int F[2][2], int n)
{
  int i;
  int M[2][2] = {{1,1},{1,0}};
  for (i = 2; i <= n; i++)
      multiply(F, M);
}
