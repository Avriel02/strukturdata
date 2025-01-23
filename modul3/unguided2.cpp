#include <iostream>
#include <sstream>

using namespace std;

// Fungsi untuk mengembalikan string representasi matriks
string matrixToString(int **matrix, int rows, int cols)
{
    stringstream ss;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            ss << matrix[i][j] << " ";
        }
        ss << endl;
    }
    return ss.str();
}

int main()
{
    int rows, cols;

    cout << "Masukkan jumlah baris: ";
    cin >> rows;

    cout << "Masukkan jumlah kolom: ";
    cin >> cols;

    // Mengalokasikan memori untuk matriks
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }

    // Memasukkan nilai matriks dari pengguna
    cout << "Masukkan elemen matriks:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    // Mendapatkan string representasi matriks
    string matrixString = matrixToString(matrix, rows, cols);

    // Mencetak string representasi matriks ke layar
    cout << "Matriks yang dimasukkan:" << endl;
    cout << matrixString;

    // Membebaskan memori matriks
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
