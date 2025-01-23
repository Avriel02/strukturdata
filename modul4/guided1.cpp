#include <iostream>
using namespace std;

struct Buku
{
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    int harga_buku[5];
};

int main()
{
    struct Buku book;
    book.judul_buku[0] = "HUJAN";
    book.pengarang[0] = "Tere Liye";
    book.penerbit[0] = "Republika";
    book.tebal_halaman[0] = 1500;
    book.harga_buku[0] = 120000;

    book.judul_buku[1] = "the catcher in the rye";
    book.pengarang[1] = "J.D Salinger";
    book.penerbit[1] = "Republika";
    book.tebal_halaman[1] = 224;
    book.harga_buku[1] = 45000;

    book.judul_buku[2] = "1984";
    book.pengarang[2] = "george orwell";
    book.penerbit[2] = "Republika";
    book.tebal_halaman[2] = 3200;
    book.harga_buku[2] = 125000;

    book.judul_buku[3] = "bumi";
    book.pengarang[3] = "Tere Liye";
    book.penerbit[3] = "gramedia";
    book.tebal_halaman[3] = 540;
    book.harga_buku[3] = 85000;

    book.judul_buku[4] = "bulan";
    book.pengarang[4] = "Tere Liye";
    book.penerbit[4] = "gramedia";
    book.tebal_halaman[4] = 460;
    book.harga_buku[4] = 90000;

    for (int i = 0; i < 5; i++)
    {
        cout << "Buku ke-" << i + 1 << endl;
        cout << "Judul buku : " << book.judul_buku[i] << endl;
        cout << "pengarang  : " << book.pengarang[i] << endl;
        cout << "penerbit   : " << book.penerbit[i] << endl;
        cout << "tebal halaman : " << book.tebal_halaman[i] << endl;
        cout << "harga buku : Rp" << book.harga_buku[i] << endl;
    }
    return 0;
}