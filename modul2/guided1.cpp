#include <iostream>
using namespace std;
int main()
{
    int jumlah = 30;
    string negara = "Indonesia";
    float volume = 17.25;
    bool sehat = true;
    cout << "alamat dari jumlah " << &jumlah << endl;
    cout << "alamat dari negara " << &negara << endl;
    cout << "alamat dari volume " << &volume << endl;
    cout << "alamat dari sehat " << &sehat << endl;
}