#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define M_I 1000000

using namespace std;

int ar[M_I], tmp[M_I];

clock_t t_merge, t_quick, t_gnome, start;

int merge_rep = 0;
int quick_rep = 0;
int gnome_rep = 0;


void VEC_CPY(int n)
{
    for (int i = 0; i < n; i++)
    {
        tmp[i] = ar[i];
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void flip(int arr[], int i)
{
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findMax(int arr[], int n)
{
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
        merge_rep++;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
        quick_rep++;
    }
}

void gnomeSort(int arr[], int n)
{
    int index = 0;
    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
            gnome_rep++;
        }
    }
    return;
}
void ReadArray(int n)
{
    for (int i = 0; i < n; i++)
    {
        ar[i] = rand();
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    unsigned long long n;
    int option;
    cout << "Introduceti nr de elemente ce trebuie sortate: ";
    cin >> n;
    ReadArray(n);
    system("cls");
    cout << "----------------------------------------------------------" << endl;
    cout << "------------------------ALGORITHMS------------------------" << endl;
    cout << "\n1.MERGE SORT \n2.QUICK SORT \n3.GNOME SORT \n4.EXIT" << endl;
    do
    {
        cout << "Selecteaza unul din algoritmii propusi: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            VEC_CPY(n);
            start = clock();
            t_merge = clock() - start;
            cout << "VECTORUL INITIAL: ";
            printArray(ar, n);
            mergeSort(tmp, 0, n - 1);
            cout << "\nVECTORUL SORTAT: ";
            printArray(tmp, n);
            cout << "Timpul de executie: " << (float)t_merge / CLOCKS_PER_SEC << endl;
            cout << "Iteratii: " << merge_rep << endl;
            cout << "----------------------------------------------------------" << endl;
            break;
        }
        case 2:
        {
            VEC_CPY(n);
            cout << "VECTORUL INITIAL: ";
            printArray(ar, n);
            start = clock();
            quickSort(tmp, 0, n - 1);
            t_quick = clock() - start;
            cout << "VECTORUL SORTAT: ";
            printArray(tmp, n);
            cout << "Timpul de executie: " << (float)t_quick / CLOCKS_PER_SEC << endl;
            cout << "Iteratii: " << quick_rep << endl;
            cout << "----------------------------------------------------------" << endl;
            break;
        }
        case 3:
        {
            VEC_CPY(n);
            cout << "VECTORUL INITIAL: ";
            printArray(ar, n);
            start = clock();
            gnomeSort(tmp, n);
            t_gnome = clock() - start;
            cout << "VECTORUL SORTAT: ";
            printArray(tmp, n);
            cout << "Timpul de executie: " << (float)t_gnome / CLOCKS_PER_SEC << endl;
            cout << "Iteratii: " << gnome_rep << endl;
            cout << "----------------------------------------------------------" << endl;
            break;
        }

        case 4:
        {
            cout << "Iesire din program...";
            exit(1);
            break;
        }
        }
    } while (option != 4);
    return 0;
}
