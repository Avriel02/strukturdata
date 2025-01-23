#include <iostream>

using namespace std;

int main()
{
    int baris, kolom;

    // Meminta pengguna untuk memasukkan jumlah baris dan kolom
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    // Membuat matriks berukuran dinamis
    int **matriks = new int *[baris];
    for (int i = 0; i < baris; ++i)
    {
        matriks[i] = new int[kolom];
    }

    // Memasukkan elemen-elemen matriks
    cout << "Masukkan elemen matriks:" << endl;
    for (int i = 0; i < baris; ++i)
    {
        for (int j = 0; j < kolom; ++j)
        {
            cin >> matriks[i][j];
        }
    }

    // Mencetak matriks
    cout << "Matriks yang dimasukkan:" << endl;
    for (int i = 0; i < baris; ++i)
    {
        for (int j = 0; j < kolom; ++j)
        {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    // Menghapus matriks dari memori
    for (int i = 0; i < baris; ++i)
    {
        delete[] matriks[i];
    }
    delete[] matriks;

    return 0;
}
