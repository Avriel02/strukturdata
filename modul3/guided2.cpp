#include <iostream>
using namespace std;

float matriksA[7][9];
float matriksB[7][9];
int main()
{
    for (int baris = 0; baris < 7; baris++)
    {
        for (int kolom = 0; kolom < 9; kolom++)
        {
            matriksA[baris][kolom] = 1 + kolom + baris;
            matriksB[baris][kolom] = 3 + kolom + baris;
        }
    }
    for (int baris = 0; baris < 7; baris++)
    {
        for (int kolom = 0; kolom < 9; kolom++)
        {
            cout << matriksA[baris][kolom] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    for (int baris = 0; baris < 7; baris++)
    {
        for (int kolom = 0; kolom < 9; kolom++)
        {
            cout << matriksB[baris][kolom] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    cout << "Hasil Pengurangn matriks A dan matriks B" << endl;
    for (int baris = 0; baris < 7; baris++)
    {
        for (int kolom = 0; kolom < 9; kolom++)
        {
            cout << matriksA[baris][kolom] - matriksB[baris][kolom] << " ";
        }
        cout << endl;
    }
    cout << "Hasil Pengurangan matriks B dan matriks A" << endl;
    for (int baris = 0; baris < 7; baris++)
    {
        for (int kolom = 0; kolom < 9; kolom++)
        {
            cout << matriksB[baris][kolom] - matriksA[baris][kolom] << " ";
        }
        cout << endl;
    }

    return 0;
}