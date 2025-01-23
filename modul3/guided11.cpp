#include <iostream>
using namespace std;

int matrixB[2][3] = {
    {6, 5, 4},
    {3, 2, 1}};
int matrixA[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}};
int result[2][4];

int main()
{
    for (int rows = 0; rows < 2; rows++)
    {
        for (int column = 0; column < 4; column++)
        {
            result[rows][column] = 0;
            for (int k = 0; k < 3; ++k)
            {
                result[rows][column] += matrixB[rows][k] * matrixA[k][column];
            }
            cout << result[rows][column] << " ";
        }
        cout << endl;
    }
    return 0;
}