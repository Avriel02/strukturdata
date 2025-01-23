#include <iostream>
using namespace std;

struct melist
{
    string data;
    melist *next;
};

melist *head = NULL;
melist *tail = NULL;

void inisialisasi()
{
    head = NULL;
    tail = NULL;
}

bool list_kosong()
{
    return (head == NULL);
}

melist *buat_simpul(string dataMasukkan)
{
    melist *simpul_baru = new melist;
    simpul_baru->data = dataMasukkan;
    simpul_baru->next = NULL;
    return simpul_baru;
}

void tambah_belakang(string data_user)
{
    melist *simpul_baru = buat_simpul(data_user);
    if (list_kosong())
    {
        head = simpul_baru;
        tail = simpul_baru;
    }
    else
    {
        tail->next = simpul_baru;
        tail = simpul_baru;
    }
    tail->next = head;
}

void tambah_depan(string data_user)
{
    melist *simpul_baru = buat_simpul(data_user);
    if (list_kosong())
    {
        head = simpul_baru;
        tail = simpul_baru;
        tail->next = head;
    }
    else
    {
        simpul_baru->next = head;
        head = simpul_baru;
        tail->next = head;
    }
}

void hapus_belakang()
{
    if (list_kosong())
    {
        cout << "Tidak ada data" << endl;
    }
    else
    {
        melist *temp = head, *prev = NULL;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev)
        {
            prev->next = head;
            tail = prev;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        delete temp;
    }
}

void hapus_depan()
{
    if (list_kosong())
    {
        cout << "Tidak ada data" << endl;
    }
    else
    {
        melist *temp = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete temp;
    }
}

void tampil_data()
{
    if (list_kosong())
    {
        cout << "Tidak ada data" << endl;
    }
    else
    {
        melist *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
}

int main()
{
    int pilihan;
    string data_user;

    do
    {
        cout << "Menu:\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Hapus Depan\n";
        cout << "4. Hapus Belakang\n";
        cout << "5. Tampil Data linkedlist\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan data: ";
            cin >> data_user;
            tambah_depan(data_user);
            break;
        case 2:
            cout << "Masukkan data: ";
            cin >> data_user;
            tambah_belakang(data_user);
            break;
        case 3:
            hapus_depan();
            break;
        case 4:
            hapus_belakang();
            break;
        case 5:
            cout << "Data linked list: ";
            tampil_data();
            break;
        case 6:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);

    return 0;
}
