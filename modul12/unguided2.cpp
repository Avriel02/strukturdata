#include <iostream>
#include <string>
#include <vector>
using namespace std;

int jumlahSimpul;
string *dataSimpul;
int **dataBusur;
bool cekMatrik = false;
int simpulAsal, simpulTujuan;

void buatMatriks()
{
    cout << "Masukkan jumlah kota: ";
    cin >> jumlahSimpul;

    dataSimpul = new string[jumlahSimpul];
    dataBusur = new int *[jumlahSimpul];
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul];
    for (int i = 1; i < jumlahSimpul; i++)
    {
        dataBusur[i] = dataBusur[i - 1] + jumlahSimpul;
    }

    cout << "Masukkan nama simpul:" << endl;
    for (int i = 0; i < jumlahSimpul; i++)
    {
        cout << "Kota " << i + 1 << " : ";
        cin >> dataSimpul[i];
    }

    cout << "Masukkan bobot antar simpul:" << endl;
    for (int baris = 0; baris < jumlahSimpul; baris++)
    {
        for (int kolom = 0; kolom < jumlahSimpul; kolom++)
        {
            cout << dataSimpul[baris] << " --> " << dataSimpul[kolom] << " : ";
            cin >> dataBusur[baris][kolom];
        }
    }
    cekMatrik = true;
}

void tampilMatriks()
{
    if (cekMatrik)
    {
        for (int i = 0; i < jumlahSimpul; i++)
        {
            cout << dataSimpul[i] << " ";
        }
        cout << endl;
        for (int baris = 0; baris < jumlahSimpul; baris++)
        {
            for (int kolom = 0; kolom < jumlahSimpul; kolom++)
            {
                cout << dataBusur[baris][kolom] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Tidak ada matriks" << endl;
    }
}

void hitungJarakTerdekatDijkstra()
{
    if (cekMatrik)
    {
        vector<int> jarakDiketahui(jumlahSimpul, 999);
        vector<bool> kunjungan(jumlahSimpul, false);
        jarakDiketahui[simpulAsal] = 0;

        for (int i = 0; i < jumlahSimpul - 1; i++)
        {
            int min = 999, min_index;
            for (int v = 0; v < jumlahSimpul; v++)
            {
                if (!kunjungan[v] && jarakDiketahui[v] <= min)
                {
                    min = jarakDiketahui[v];
                    min_index = v;
                }
            }

            int u = min_index;
            kunjungan[u] = true;

            for (int v = 0; v < jumlahSimpul; v++)
            {
                if (!kunjungan[v] && dataBusur[u][v] && jarakDiketahui[u] != 999 && jarakDiketahui[u] + dataBusur[u][v] < jarakDiketahui[v])
                {
                    jarakDiketahui[v] = jarakDiketahui[u] + dataBusur[u][v];
                }
            }
        }

        cout << "Jarak terdekat dari " << dataSimpul[simpulAsal] << " ke " << dataSimpul[simpulTujuan] << " adalah " << jarakDiketahui[simpulTujuan] << endl;
    }
}

void hitungJarakTerdekatFloydWarshall()
{
    if (cekMatrik)
    {
        int jarak[jumlahSimpul][jumlahSimpul];
        for (int i = 0; i < jumlahSimpul; i++)
        {
            for (int j = 0; j < jumlahSimpul; j++)
            {
                jarak[i][j] = dataBusur[i][j];
            }
        }

        for (int k = 0; k < jumlahSimpul; k++)
        {
            for (int i = 0; i < jumlahSimpul; i++)
            {
                for (int j = 0; j < jumlahSimpul; j++)
                {
                    if (jarak[i][k] + jarak[k][j] < jarak[i][j])
                    {
                        jarak[i][j] = jarak[i][k] + jarak[k][j];
                    }
                }
            }
        }

        cout << "Jarak terdekat dari " << dataSimpul[simpulAsal] << " ke " << dataSimpul[simpulTujuan] << " adalah " << jarak[simpulAsal][simpulTujuan] << endl;
    }
}

void menuDijkstra()
{
    cout << "Algoritma Dijkstra:" << endl;
    cout << "Masukkan simpul asal (0 - " << jumlahSimpul - 1 << "): ";
    cin >> simpulAsal;
    cout << "Masukkan simpul tujuan (0 - " << jumlahSimpul - 1 << "): ";
    cin >> simpulTujuan;
    hitungJarakTerdekatDijkstra();
}

void menuFloydWarshall()
{
    cout << "Algoritma Floyd-Warshall:" << endl;
    cout << "Masukkan simpul asal (0 - " << jumlahSimpul - 1 << "): ";
    cin >> simpulAsal;
    cout << "Masukkan simpul tujuan (0 - " << jumlahSimpul - 1 << "): ";
    cin >> simpulTujuan;
    hitungJarakTerdekatFloydWarshall();
}

int main()
{
    int pilihan;
    buatMatriks();
    tampilMatriks();

    while (true)
    {
        cout << "====== Menu Utama ======" << endl;
        cout << "1. Cari Jalur Terpendek dengan Dijkstra" << endl;
        cout << "2. Cari Jalur Terpendek dengan Floyd-Warshall" << endl;
        cout << "3. Tampilkan Matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan (1-4): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            menuDijkstra();
            break;
        case 2:
            menuFloydWarshall();
            break;
        case 3:
            tampilMatriks();
            break;
        case 4:
            cout << "Terima kasih telah menggunakan program ini." << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    }
    return 0;
}
