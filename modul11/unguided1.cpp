#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int jumlahSimpul = 5;
vector<string> dataSimpul;
vector<vector<int>> dataBusur;

struct graph
{
    string data;
    vector<pair<graph *, int>> adj;
};

vector<graph> simpulGraph;

void inisiasi()
{
    simpulGraph.clear();
}

void buatMatriks()
{
    dataSimpul.resize(jumlahSimpul);
    dataBusur.resize(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Silahkan masukkan nama simpul " << endl;
    for (int i = 0; i < jumlahSimpul; i++)
    {
        cout << "Kota " << i + 1 << " : ";
        cin >> dataSimpul[i];
    }

    cout << "Silahkan masukkan bobot antar simpul " << endl;
    for (int baris = 0; baris < jumlahSimpul; baris++)
    {
        for (int kolom = 0; kolom < jumlahSimpul; kolom++)
        {
            cout << dataSimpul[baris] << " --> " << dataSimpul[kolom] << " : ";
            cin >> dataBusur[baris][kolom];
        }
    }
}

void buatSimpulGraph()
{
    buatMatriks();
    simpulGraph.resize(jumlahSimpul);

    for (int i = 0; i < jumlahSimpul; i++)
    {
        simpulGraph[i].data = dataSimpul[i];
    }

    for (int i = 0; i < jumlahSimpul; i++)
    {
        for (int j = 0; j < jumlahSimpul; j++)
        {
            if (dataBusur[i][j] != 0)
            {
                simpulGraph[i].adj.push_back(make_pair(&simpulGraph[j], dataBusur[i][j]));
            }
        }
    }
}

void tampilGraph()
{
    for (int i = 0; i < jumlahSimpul; i++)
    {
        cout << simpulGraph[i].data << " : ";
        for (auto &adjNode : simpulGraph[i].adj)
        {
            cout << adjNode.first->data << " : " << adjNode.second << " ";
        }
        cout << endl;
    }
}

int minDistance(vector<int> &dist, vector<bool> &sptSet)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < jumlahSimpul; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int src)
{
    vector<int> dist(jumlahSimpul, INT_MAX);
    vector<bool> sptSet(jumlahSimpul, false);
    dist[src] = 0;

    for (int count = 0; count < jumlahSimpul - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < jumlahSimpul; v++)
        {
            if (!sptSet[v] && dataBusur[u][v] && dist[u] != INT_MAX && dist[u] + dataBusur[u][v] < dist[v])
            {
                dist[v] = dist[u] + dataBusur[u][v];
            }
        }
    }

    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < jumlahSimpul; i++)
    {
        cout << dataSimpul[i] << " \t\t " << dist[i] << endl;
    }
}

int main()
{
    inisiasi();
    cout << "Silahkan masukkan jumlah kota : ";
    cin >> jumlahSimpul;
    buatSimpulGraph();
    tampilGraph();

    cout << "Masukkan indeks kota awal untuk mencari jalur terpendek: ";
    int src;
    cin >> src;
    dijkstra(src);

    return 0;
}
