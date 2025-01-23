#include <iostream>
using namespace std;

struct pohon
{
    pohon *kanan; // yang ngarahin kanan
    char data;    // menyimpan data
    pohon *kiri;  // yang ngarahin kiri
};

pohon *simpul;      // membuat node baru/ menyimpan data baru
pohon *root;        // menyimpan root binary tree
pohon *saatIni;     // menyimpan node yang sedang di proses
pohon *alamat[256]; // array menyimpan alamat-alamat simpul

// inisialisasi nilai root
void inisialisasi()
{
    root = NULL; // membuat binary tree kosong tidak ada datanya,
    // setting root pointing to null
}
// menambahkan simpul // node
void simpulBaru(char dataMasukan)
{
    simpul = new pohon;         // membuat simpul baru
    simpul->data = dataMasukan; // field with data in parameter
    simpul->kanan = NULL;       // simpul kanan NULL
    simpul->kiri = NULL;        // simpul kiri NULL
}

// menambahkan simpul akar /simpul yang paling utama
void simpulAkar()
{
    if (root == NULL) // akan mengecek apakah rootnya sama dengan null, jika masuk kosong program akan membuat variable

    {
        char dataAnda;                      // membuat variabel baru dataanda bertipe data char
        cout << "Silahkan masukkan data: "; // user menginput data secara manual
        cin >> dataAnda;                    // inputan tersimpan ke data anda
        simpulBaru(dataAnda);               // memanggil simpul baru dengan argumen data anda
        root = simpul;                      // data yang dimasukan berupa nilai root menjadi nilai simpul, pointing root to simpul
        cout << "Root Terbentuk" << endl;   // menampilkan nilai root terbentuk jika nilai sama dengan null
    }
    else
    {
        cout << "Root sudah ada. " << endl; // jika tidak sama dengan null akan menampilkan root sudah ada
    }
}
// fungsi untuk menambahkan simpul baru setelah menambahkan root
void tambahSimpul()
{
    if (root != NULL) // cek rootnya harus tidak sama dengan null agar bisa menambahkan kanan kirinya
    {
        int i = 1;        // sebagai variabel index untuk alamat simpul array
        int j = 1;        // sebagai variabel index untuk alamat simpul array
        int penanda = 0;  // mengontrol loop while
        char dataUser;    // menyimpan masukan user
        alamat[i] = root; // deklarasi nilai alamat dengan root

        while (penanda == 0 && j < 10) // dimana nilai penanda sama dengan 0 dan j kurang dari sama 10
        {
            cout << "Masukan data kiri : ";
            cin >> dataUser;     // mennyipan data user
            if (dataUser != '0') // jika nilai tidak sama dengan 0 maka
            {
                simpulBaru(dataUser);
                saatIni = alamat[i];    // pointing saat ini to alamat i = 1
                saatIni->kiri = simpul; // menyimpan data user di root kiri
                j++;                    // index terus bertambah menjadi 2
                alamat[j] = simpul;     // mengisi nilai alamat i dengan simpul // pointer alamat dengan index 2 menujuk ke simpul
            }
            else // jika nilai data user sama dengan 0
            {
                penanda = 1; // maka nilai penanda sama dengan 1
                j++;
                alamat[j] = NULL; // nilai alamat j di isi dengan NULL
            }

            if (penanda == 0) // program untuk menyimpan nilai kanan
            {
                cout << "Masukan data kanan : "; //
                cin >> dataUser;                 // c
                if (dataUser != '0')             // mengecek apakah data user sama dengan 0
                {
                    simpulBaru(dataUser);    // membuat simpul baru dengan argumen c
                    saatIni = alamat[i];     // mengarahkan saat ini ke arah alamat 1 yaitu root
                    saatIni->kanan = simpul; //
                    j++;                     // index terus bertambah menjadi 3
                    alamat[j] = simpul;      // alamat 3 sama dengan simpul//pointer alamat dengan index 3 diarahkan ke simpul
                }
                else
                {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++; // i menjadi 2 //setelah sampai i++ balik lagi ke while karan perulangan
        }
    }
}

void bacaPohon()
{
    if (root != NULL)
    {
        int i, n, pencacah;
        i = 1; // mengakses elemen array di dalam alamat
        n = 1;
        pencacah = 0; // menghitung jumlah simpul yang sudah di cetak
        cout << endl;
        while (alamat[i] != NULL) // perulangan untuk mencetak data data yang sudah dimasukan
        {
            saatIni = alamat[i]; // pointer saat ini di deklarasika dengan alamat i
            cout << saatIni->data << " ";
            pencacah++;        // untuk menghitung jumlah simpul yang sudah di tata
            if (pencacah == n) // nilai pencacah sama dengan n
            {
                cout << endl;
                pencacah = 0; // nilai pencacahnya sama dengan 0
                n = n * 2;    // nilai n di dapat dengan n kali 2
            }
            i++;
        }
    }
}

void telusurPreOrder(pohon *asal) // ketika dipanggil argumen berupa root
{
    if (asal != NULL)
    {

        cout << asal->data << " ";    // tampil data
        telusurPreOrder(asal->kiri);  // cek kiri
        telusurPreOrder(asal->kanan); // cek kanan
    }
}

void telusurInOrder(pohon *asal)
{
    if (asal != NULL)
    {
        telusurInOrder(asal->kiri);  // cek kiri
        cout << asal->data << " ";   // tampil data
        telusurInOrder(asal->kanan); // cek kanan
    }
}

void telusurPosOrder(pohon *asal)
{
    if (asal != NULL)
    {
        telusurPosOrder(asal->kiri);  // cek kiri
        telusurPosOrder(asal->kanan); // cek kanan
        cout << asal->data << " ";    // tampil data
    }
}
//

void greeting(int b) //
{

    if (b > 0)
    {
        cout << "Hello" << endl;
        greeting(b - 1);
    }
}

int perkalian(int a, int b)
{
    if (b != 0)
    {
        return a + perkalian(a, b - 1);
    }
    else
    {
        return 0;
    }
}
int main()
{
    /*
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    cout << "Hasil Pre-Order :";
    telusurPreOrder(root);
    cout << "Hasil In-Order :";
    telusurInOrder(root);
    cout << "Hasil Pos-Order :";
    telusurPosOrder(root);
    */
    greeting(3);
    cout << perkalian(2, 4);
    return 0;
}