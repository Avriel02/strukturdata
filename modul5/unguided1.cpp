#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;

const int maksimal_tumpukan = 10;
bool keluar = false;
char ya_tidak;
int pilihan;

struct Buku
{
    string judul;
    string pengarang;
    int jumlah_halaman;
    double harga;
};

struct tumpukan
{
    int posisi;
    Buku data[maksimal_tumpukan];
};

tumpukan buku;

void inisialisasi()
{
    buku.posisi = -1;
}

bool kosong()
{
    return (buku.posisi == -1);
}

bool penuh()
{
    return (buku.posisi == maksimal_tumpukan - 1);
}

void push_tumpukan(Buku data_masukkan)
{
    if (penuh())
    {
        cout << "Tumpukan sudah penuh" << endl;
    }
    else
    {
        buku.posisi++;
        buku.data[buku.posisi] = data_masukkan;
        cout << "Berhasil memasukkan data buku" << endl;
    }
}

void pop_tumpukan()
{
    if (kosong())
    {
        cout << "Tumpukan kosong" << endl;
    }
    else
    {
        buku.posisi--;
        cout << "Data berhasil dihapus dari tumpukan" << endl;
    }
}

void tampil_data()
{
    if (kosong())
    {
        cout << "Tidak ada data" << endl;
    }
    else
    {
        for (int c = buku.posisi; c >= 0; c--)
        {
            cout << "Buku ke-" << c + 1 << endl;
            cout << "Judul: " << buku.data[c].judul << endl;
            cout << "Pengarang: " << buku.data[c].pengarang << endl;
            cout << "Jumlah Halaman: " << buku.data[c].jumlah_halaman << endl;
            cout << "Harga: " << buku.data[c].harga << endl
                 << endl;
        }
    }
}

int main()
{
    inisialisasi();

    do
    {
        cout << "\t"
             << "Stack Apps" << endl;
        cout << "1. Masukkan data buku ke dalam Stack" << endl;
        cout << "2. Hapus data buku dari Stack" << endl;
        cout << "3. Tampilkan data Stack" << endl;
        cout << "4. Keluar" << endl;
        cout << "Silahkan pilih (1-4) : ";

        while (!(cin >> pilihan))
        {
            cout << "Masukan tidak valid. Silahkan masukkan nomor pilihan (1-4): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihan)
        {
        case 1:
        {
            Buku buku_baru;
            cout << "Masukkan data buku:" << endl;
            cout << "Judul: ";
            cin.ignore();
            getline(cin, buku_baru.judul);
            cout << "Pengarang: ";
            getline(cin, buku_baru.pengarang);
            cout << "Jumlah Halaman: ";
            cin >> buku_baru.jumlah_halaman;
            cout << "Harga: ";
            cin >> buku_baru.harga;
            push_tumpukan(buku_baru);
            break;
        }
        case 2:
            pop_tumpukan();
            break;

        case 3:
            tampil_data();
            break;

        case 4:
            cout << "Yakin ingin keluar (y/t) ? ";
            cin >> ya_tidak;
            if (ya_tidak == 'y' || ya_tidak == 'Y')
            {
                cout << "Terima kasih" << endl;
                keluar = true;
            }
            break;

        default:
            cout << "Pilihan tidak tersedia..." << endl;
            break;
        }

        if (!keluar)
        {
            cout << "Kembali ke menu utama (y/t) ? ";
            cin >> ya_tidak;
            if (ya_tidak == 't' || ya_tidak == 'T')
            {
                keluar = true;
            }
            else
            {
                system("cls");
            }
        }

    } while (!keluar);

    return 0;
}
