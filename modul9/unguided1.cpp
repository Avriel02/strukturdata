#include <iostream>
using namespace std;

struct pohon
{
    pohon *kanan;
    char data;
    pohon *kiri;
};

pohon *simpul;
pohon *root;
pohon *saatIni;
pohon *alamat[256];

void inisialisasi()
{
    root = NULL;
}

void simpulBaru(char dataMasukan)
{
    simpul = new pohon;
    simpul->data = dataMasukan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

void simpulAkar()
{
    if (root == NULL)
    {
        char dataAnda;
        cout << "Silahkan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root Terbentuk" << endl;
    }
    else
    {
        cout << "Root sudah ada." << endl;
    }
}

pohon *cariSimpul(pohon *node, char data)
{
    if (node == NULL || node->data == data)
        return node;

    pohon *result = cariSimpul(node->kiri, data);
    if (result != NULL)
        return result;

    return cariSimpul(node->kanan, data);
}

void tambahSimpul()
{
    if (root != NULL)
    {
        char parentData, dataUser;
        char posisi;

        cout << "Masukkan data dari simpul parent: ";
        cin >> parentData;

        pohon *parentNode = cariSimpul(root, parentData);

        if (parentNode != NULL)
        {
            cout << "Masukkan data untuk simpul baru: ";
            cin >> dataUser;

            cout << "Ingin menambahkan simpul ke kiri (k) atau ke kanan (n)? ";
            cin >> posisi;

            simpulBaru(dataUser);

            if (posisi == 'k' && parentNode->kiri == NULL)
            {
                parentNode->kiri = simpul;
                cout << "Simpul baru ditambahkan ke kiri dari " << parentData << endl;
            }
            else if (posisi == 'n' && parentNode->kanan == NULL)
            {
                parentNode->kanan = simpul;
                cout << "Simpul baru ditambahkan ke kanan dari " << parentData << endl;
            }
            else
            {
                cout << "Posisi yang dipilih sudah terisi atau tidak valid." << endl;
            }
        }
        else
        {
            cout << "Simpul parent tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << "Pohon biner kosong, tambahkan simpul akar terlebih dahulu." << endl;
    }
}

void bacaPohon(pohon *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        bacaPohon(node->kiri);
        bacaPohon(node->kanan);
    }
}

int main()
{
    inisialisasi();
    simpulAkar();
    char choice;
    do
    {
        tambahSimpul();
        cout << "Ingin menambahkan simpul lagi? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    cout << "Data pohon biner :" << endl;
    bacaPohon(root);
    cout << endl;

    return 0;
}
