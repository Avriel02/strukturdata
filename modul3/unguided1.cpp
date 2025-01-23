#include <iostream>

using namespace std;

int main()
{
    double A[2][2] = {{5, 4}, {3, 8}};
    double B[2][2] = {{25, 13}, {10, 9}};
    double A_inverse[2][2];
    double B_inverse[2][2];

    // Mencetak matriks A
    cout << "Matriks A = " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Menghitung determinan matriks A
    double det_A = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    // Mengecek apakah matriks A memiliki invers
    if (det_A == 0)
    {
        cout << "Matriks A tidak memiliki invers karena determinannya nol." << endl;
        return 1;
    }

    // Menghitung matriks invers A
    A_inverse[0][0] = A[1][1];
    A_inverse[0][1] = -A[0][1];
    A_inverse[1][0] = -A[1][0];
    A_inverse[1][1] = A[0][0];

    // Mencetak invers matriks A
    cout << "Invers A = " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << A_inverse[i][j] / det_A << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Mencetak matriks B
    cout << "Matriks B = " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Menghitung determinan matriks B
    double det_B = B[0][0] * B[1][1] - B[0][1] * B[1][0];

    // Mengecek apakah matriks B memiliki invers
    if (det_B == 0)
    {
        cout << "Matriks B tidak memiliki invers karena determinannya nol." << endl;
        return 1;
    }

    // Menghitung matriks invers B
    B_inverse[0][0] = B[1][1];
    B_inverse[0][1] = -B[0][1];
    B_inverse[1][0] = -B[1][0];
    B_inverse[1][1] = B[0][0];

    // Mencetak invers matriks B
    cout << "Invers B = " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << B_inverse[i][j] / det_B << " ";
        }
        cout << endl;
    }

    return 0;
}
