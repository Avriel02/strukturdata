#include <iostream>
#include <string>
using namespace std;

struct B
{
    string Judul_Buku[5];
    string Pengarang[5];
    string penerbit[5];
    int tebal_Halaman[5];
    float harga_buku[5];
};

int main()
{
    struct B buku = {
        {"Buku 1", "Buku 2", "Buku 3", "Buku 4", "Buku 5"},
        {"Pengarang 1", "Pengarang 2", "Pengarang 3", "Pengarang 4", "Pengarang 5"},
        {"Penerbit 1", "Penerbit 2", "Penerbit 3", "Penerbit 4", "Penerbit 5"},
        {100, 150, 200, 250, 300},
        {50.000, 60.000, 70.000, 80.000, 90.000}};

    for (int i = 0; i < 5; ++i)
    {
        cout << "Data Buku " << i + 1 << endl;
        cout << "Judul Buku: " << buku.Judul_Buku[i] << endl;
        cout << "Pengarang: " << buku.Pengarang[i] << endl;
        cout << "Penerbit: " << buku.penerbit[i] << endl;
        cout << "Tebal Halaman: " << buku.tebal_Halaman[i] << endl;
        cout << "Harga Buku: " << buku.harga_buku[i] << endl;
    }

    return 0;
}
