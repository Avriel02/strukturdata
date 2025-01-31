#include <iostream>
#include <string>
#include <vector>
using namespace std;
int jumlahSimpul = 5;
string *dataSimpul;
int **dataBusur;
bool cekMatrik = false;
int indeksPosisi, simpulSaatIni, simpulAsal, simpulTujuan, jarakSaatIni,
    jarakLama, jarakBaru;
int dikunjungi = 1;
int belumDikunjungi = 0;
int *jarakDiketahui;
int *kunjungan;
vector<int> jalurTerpendek;
void buatMatriks()
{
    dataSimpul = new string[jumlahSimpul];
    dataBusur = new int *[jumlahSimpul];
    dataBusur[0] = new int[jumlahSimpul * jumlahSimpul];
    for (int i = 1; i < jumlahSimpul; i++)
    {
        dataBusur[i] = dataBusur[i - 1] + jumlahSimpul;
    }
    cout << "Silahkan masukkan nama simpul " << endl;
    for (int i = 0; i < jumlahSimpul; i++)
    {
        cout << "Huruf " << i + 1 << " : ";
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
    cekMatrik = true;
}
void hitungJarakTerdekat()
{
    if (cekMatrik)
    {
        jarakDiketahui = new int[jumlahSimpul];
        kunjungan = new int[jumlahSimpul];
        for (int i = 0; i < jumlahSimpul; i++)
        {
            jarakDiketahui[i] = 99;
            kunjungan[i] = belumDikunjungi;
        }
        kunjungan[simpulAsal] = dikunjungi;
        jarakDiketahui[simpulAsal] = 0;
        simpulSaatIni = simpulAsal;
        jalurTerpendek.push_back(simpulAsal);
        while (simpulSaatIni != simpulTujuan)
        {
            jarakLama = 999;
            jarakSaatIni = jarakDiketahui[simpulSaatIni];
            for (int i = 0; i < jumlahSimpul; i++)
            {
                if (kunjungan[i] == belumDikunjungi)
                {
                    jarakBaru = jarakSaatIni +
                                dataBusur[simpulSaatIni][i];
                    if (jarakBaru < jarakDiketahui[i])
                    {
                        jarakDiketahui[i] = jarakBaru;
                    }
                    if (jarakDiketahui[i] < jarakLama)
                    {
                        jarakLama = jarakDiketahui[i];
                        indeksPosisi = i;
                    }
                }
            }
            simpulSaatIni = indeksPosisi;
            kunjungan[simpulSaatIni] = dikunjungi;
            jalurTerpendek.push_back(simpulSaatIni);
        }
        cout << "Jarak terdekat dari " << dataSimpul[simpulAsal] << " ke " << dataSimpul[simpulTujuan] << " adalah " << jarakDiketahui[simpulTujuan] << endl;
        cout << "Jalur terpendek: ";
        for (int i = 0; i < jalurTerpendek.size(); i++)
        {
            cout << dataSimpul[jalurTerpendek[i]] << " ";
        }
        cout << endl;
        delete jarakDiketahui;
        delete kunjungan;
        jalurTerpendek.clear();
    }
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
int main()
{
    char keluar;
    cout << "Silahkan masukkan jumlah huruf (angka) : ";
    cin >> jumlahSimpul;
    buatMatriks();
    tampilMatriks();
    do
    {
        cout << "Silahkan masukkan simpul asal (0 - " << jumlahSimpul - 1 << ") : ";
        cin >> simpulAsal;
        cout << "Silahkan masukkan simpul tujuan (0 - " << jumlahSimpul - 1 << ") :   ";
        cin >> simpulTujuan;
        hitungJarakTerdekat();
        cout << endl
             << endl;
        cout << "Keluar (y/t) ? : ";
        cin >> keluar;
        if (tolower(keluar) != 'y')
        {
            system("cls");
        }
    } while (tolower(keluar) != 'y');
    return 0;
}