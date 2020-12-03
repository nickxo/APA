#include <iostream>
using namespace std;
#define INF 99999
#define max 5

int minKey(int key[], bool mstSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < max; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void show(int parent[], int graph[max][max])
{
    for (int i = 1; i < max; i++)
        cout << "Varfurile " << parent[i] << " - " << i << " cu ponderea : " << graph[i][parent[i]] << endl;
}

void prime(int graph[max][max], int* it)
{
    int parent[max], key[max];
    bool mstSet[max];

    for (int i = 0; i < max; i++) {
        key[i] = INF, mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < max - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < max; v++)
        {
            (*it)++;
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    show(parent, graph);
}

void showgraph(int graph[max][max])
{
    cout << "Tabloul Introdus :" << endl;
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (j == max - 1)
            {
                if (graph[i][j] == INF) { cout << "+" << endl; }
                else { cout << graph[i][j] << endl; }
            }
            else if (graph[i][j] == INF) { cout << "+ , "; }
            else { cout << graph[i][j] << " , "; }
        }
    }
    cout << endl;
}

int main()
{
    int it = 0, random[max][max] = { 0, 3, INF, INF, 1,
                                   3, 0, 5, INF, 4,
                                  INF, 5, 0, 2, 6,
                                  INF, INF, 2, 0, 7,
                                  1, 4, 6, 7, 0 };

    int favorable[max][max] = { 0, 3, INF, INF, INF,
                                3, 0, 5, INF, INF,
                                INF, 5, 0, 2, INF,
                                INF, INF, 2, 0, 7,
                                INF, INF, INF, 7, 0 };

    int unfavorable[max][max] = { 0, 3, 8, 5, 1,
                                 3, 0, 5, 6, 4,
                                 8, 5, 0, 2, 6,
                                 5, 6, 2, 0, 7,
                                 1, 4, 6, 7, 0 };
    cout << "Algoritmul Prim in cazul random:" << endl;
    showgraph(random);
    prime(random, &it);
    cout << endl << "Nr de iteratii = " << it << endl;

    cout << endl << "Algoritmul Prim in cazul favorabil:" << endl;
    showgraph(favorable); it = 0;
    prime(favorable, &it);
    cout << endl << "Nr de iteratii = " << it << endl;

    cout << endl << "Algoritmul Prim in cazul defavorabil" << endl;
    showgraph(unfavorable); it = 0;
    prime(unfavorable, &it);
    cout << endl << "Nr de iteratii = " << it << endl;
    return 0;
}
