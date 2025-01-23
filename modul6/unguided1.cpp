#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Deklarasi struktur untuk menyimpan informasi wahana
struct Wahana
{
    string nama;
    int kapasitas_antrian;
    int proses_dequeue;
};

int main()
{
    // Membuat objek untuk setiap wahana
    Wahana tong_setan = {"Tong Setan", 25, 10};
    Wahana rumah_hantu = {"Rumah Hantu", 10, 2};
    Wahana bianglala = {"Bianglala", 35, 15};
    Wahana ombak_banyu = {"Ombak Banyu", 15, 5};

    // Membuat antrian untuk setiap wahana menggunakan queue
    queue<string> antrian_tong_setan;
    queue<string> antrian_rumah_hantu;
    queue<string> antrian_bianglala;
    queue<string> antrian_ombak_banyu;

    // Variabel untuk menyimpan pilihan menu
    int pilihan;

    do
    {
        // Menampilkan menu
        cout << "Menu Pasar Malam:" << endl;
        cout << "1. Antri di Tong Setan" << endl;
        cout << "2. Antri di Rumah Hantu" << endl;
        cout << "3. Antri di Bianglala" << endl;
        cout << "4. Antri di Ombak Banyu" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih wahana yang ingin Anda antri: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            if (antrian_tong_setan.size() < tong_setan.kapasitas_antrian)
            {
                antrian_tong_setan.push("Pengunjung");
                cout << "Anda telah berhasil mengantri di Tong Setan." << endl;
            }
            else
            {
                cout << "Maaf, antrian di Tong Setan sudah penuh." << endl;
            }
            break;
        case 2:
            if (antrian_rumah_hantu.size() < rumah_hantu.kapasitas_antrian)
            {
                antrian_rumah_hantu.push("Pengunjung");
                cout << "Anda telah berhasil mengantri di Rumah Hantu." << endl;
            }
            else
            {
                cout << "Maaf, antrian di Rumah Hantu sudah penuh." << endl;
            }
            break;
        case 3:
            if (antrian_bianglala.size() < bianglala.kapasitas_antrian)
            {
                antrian_bianglala.push("Pengunjung");
                cout << "Anda telah berhasil mengantri di Bianglala." << endl;
            }
            else
            {
                cout << "Maaf, antrian di Bianglala sudah penuh." << endl;
            }
            break;
        case 4:
            if (antrian_ombak_banyu.size() < ombak_banyu.kapasitas_antrian)
            {
                antrian_ombak_banyu.push("Pengunjung");
                cout << "Anda telah berhasil mengantri di Ombak Banyu." << endl;
            }
            else
            {
                cout << "Maaf, antrian di Ombak Banyu sudah penuh." << endl;
            }
            break;
        case 5:
            cout << "Terima kasih telah mengunjungi Pasar Malam!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
            break;
        }

        // Proses dequeue untuk setiap wahana sesuai dengan aturan yang ditentukan
        while (!antrian_tong_setan.empty() && tong_setan.proses_dequeue > 0)
        {
            cout << "Pengunjung di Tong Setan sedang naik." << endl;
            antrian_tong_setan.pop();
            tong_setan.proses_dequeue--;
        }

        while (!antrian_rumah_hantu.empty() && rumah_hantu.proses_dequeue > 0)
        {
            cout << "Pengunjung di Rumah Hantu sedang naik." << endl;
            antrian_rumah_hantu.pop();
            rumah_hantu.proses_dequeue--;
        }

        while (!antrian_bianglala.empty() && bianglala.proses_dequeue > 0)
        {
            cout << "Pengunjung di Bianglala sedang naik." << endl;
            antrian_bianglala.pop();
            bianglala.proses_dequeue--;
        }

        while (!antrian_ombak_banyu.empty() && ombak_banyu.proses_dequeue > 0)
        {
            cout << "Pengunjung di Ombak Banyu sedang naik." << endl;
            antrian_ombak_banyu.pop();
            ombak_banyu.proses_dequeue--;
        }

    } while (pilihan != 5);

    return 0;
}
