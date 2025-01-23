#include <iostream>
using namespace std;

string negara[5];
string *pNegara;

int main()
{
    pNegara = negara;
    for (int i = 0; i < 5; i++)
    {
        cout << "Masukkan nama negara ke " << i << " : ";
        cin >> pNegara[i];
    }

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(pNegara + i) << endl;
    }

    return 0;
}