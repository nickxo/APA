#include <iostream>
#include <cstdlib>

#define INF 99999
using namespace std;
#define max 5
int parent[max];

int find(int i)
{
    while (parent[i] != i) i = parent[i];
    return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int cost[][max], int* it)
{
    int mincost = 0;
    for (int i = 0; i < max; i++)
        parent[i] = i;

    int edge_count = 0;
    while (edge_count < max - 1) {
        int min = INF, a = -1, b = -1;
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                (*it)++;
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        cout << "Varful " << edge_count++ << ":(" << a << " , " << b << ") costul: " << min << endl;
        mincost += min;
    }
    cout << endl << "Costul Minim = " << mincost << endl;
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


    cout << "Algoritmul Kruskal in cazul random:" << endl;
    showgraph(random);
    kruskal(random, &it);
    cout << endl << "Nr de iteratii = " << it << endl;

    cout << endl << "Algoritmul Kruskal in cazul favorabil:" << endl;
    showgraph(favorable); it = 0;
    kruskal(favorable, &it);
    cout << endl << "Nr de iteratii = " << it << endl;

    cout << endl << "Algoritmul Kruskal in cazul defavorabil" << endl;
    showgraph(unfavorable); it = 0;
    kruskal(unfavorable, &it);
    cout << endl << "Nr de iteratii = " << it << endl;
    return 0;
}
