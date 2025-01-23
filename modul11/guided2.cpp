#include <iostream>
#include <string>

using namespace std;

int jumlahSimpul = 5;
string *dataSimpul; // menggunakan pointer supaya alokasinya dinamis
int **dataBusur;
bool cekMatrik = false;

void buatMatriks()
{
    // mengalokasikan memori secara dinamis
    dataSimpul = new string[jumlahSimpul];               // membuat array sebanyak jumlah simpul
    dataBusur = new int *[jumlahSimpul];                 // membuat busur sebanyak jumlah simpul
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul]; // ukuran dari bobot
    for (int i = 1; i < jumlahSimpul; i++)
    {
        dataBusur[i] = dataBusur[i - 1] + jumlahSimpul;
    }
    //

    //  to enter the name off vertex sebanyak yang kita setting
    cout << "Silahkan masukkan nama simpul " << endl;
    for (int i = 0; i < jumlahSimpul; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        cin >> dataSimpul[i];
    }
    //
    // to enter the weight of edge
    cout << "Silahkan masukkan bobot antar simpul " << endl;
    for (int baris = 0; baris < jumlahSimpul; baris++)
    {
        for (int kolom = 0; kolom < jumlahSimpul; kolom++)
        {
            cout << dataSimpul[baris] << " --> " << dataSimpul[kolom] << " : ";
            cin >> dataBusur[baris][kolom];
        }
    }
    //
    cekMatrik = true;
}
// menampilkan matriks
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

int main()
{
    cout << "Silahkan masukkan jumlah simpul : ";
    cin >> jumlahSimpul;
    buatMatriks();
    tampilMatriks();
    return 0;
}