#include <iostream>
using namespace std;
int jumlah;
string negara;
float volume;
bool sehat;

int *pointerjumlah;
string *pointernegara;
float *pointervolume;
bool *pointersehat;

int main()
{
    jumlah = 30,
    negara = "indonesia";
    volume = 17.25;
    sehat = true;

    pointerjumlah = &jumlah;
    pointernegara = &negara;
    pointervolume = &volume;
    pointersehat = &sehat;

    cout << "alamat dari jumlah " << &jumlah << "nilai dari pinter " << *pointerjumlah << endl;
    cout << "alamat dari negara " << &negara << "nilai dari pinter " << *pointernegara << endl;
    cout << "alamat dari volume " << &volume << "nilai dari pinter " << *pointervolume << endl;
    cout << "alamat dari sehat " << &sehat << "nilai dari pinter " << *pointersehat << endl;
}