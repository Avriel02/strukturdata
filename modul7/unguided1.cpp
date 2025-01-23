#include <iostream>
using namespace std;

struct linkedlist
{
    string data;
    linkedlist *next;
};

linkedlist *head = NULL;
linkedlist *tail = NULL;
linkedlist *simpul = NULL;

void buat_simpul(string data_masukkan)
{
    simpul = new linkedlist;
    simpul->data = data_masukkan;
    simpul->next = NULL;
}

void inisialisasi()
{
    head = NULL;
    tail = NULL;
}

bool simpul_kosong()
{
    return (head == NULL && tail == NULL);
}

void tambah_belakang(string data_user)
{
    if (simpul_kosong())
    {
        buat_simpul(data_user);
        head = simpul;
        tail = simpul;
    }
    else
    {
        buat_simpul(data_user);
        tail->next = simpul;
        tail = simpul;
    }
}

void tambah_depan(string data_user)
{
    if (simpul_kosong())
    {
        buat_simpul(data_user);
        head = simpul;
        tail = simpul;
    }
    else
    {
        buat_simpul(data_user);
        simpul->next = head;
        head = simpul;
    }
}

void hapus_belakang()
{
    if (simpul_kosong())
    {
        cout << "Tidak ada simpul" << endl;
    }
    else
    {
        linkedlist *helper = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            delete helper;
        }
        else
        {
            while (helper->next != tail)
            {
                helper = helper->next;
            }
            tail = helper;
            helper = helper->next;
            tail->next = NULL;
            delete helper;
        }
    }
}

void hapus_depan()
{
    if (simpul_kosong())
    {
        cout << "Tidak ada simpul" << endl;
    }
    else
    {
        linkedlist *helper = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            delete helper;
        }
        else
        {
            head = head->next;
            delete helper;
        }
    }
}

void tampil_data()
{
    if (simpul_kosong())
    {
        cout << "Tidak ada data" << endl;
    }
    else
    {
        linkedlist *helper = head;
        while (helper != NULL)
        {
            cout << helper->data << " ";
            helper = helper->next;
        }
        cout << endl;
    }
}

void tampilkan_menu()
{
    cout << "Menu:" << endl;
    cout << "1. Tambah Data di Depan" << endl;
    cout << "2. Tambah Data di Belakang" << endl;
    cout << "3. Hapus Data di Depan" << endl;
    cout << "4. Hapus Data di Belakang" << endl;
    cout << "5. Tampilkan Data" << endl;
    cout << "6. Keluar" << endl;
}

int main()
{
    int pilihan;
    string data;

    do
    {
        tampilkan_menu();
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            tambah_depan(data);
            break;
        case 2:
            cout << "Masukkan data: ";
            cin >> data;
            tambah_belakang(data);
            break;
        case 3:
            hapus_depan();
            break;
        case 4:
            hapus_belakang();
            break;
        case 5:
            tampil_data();
            break;
        case 6:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (pilihan != 6);

    return 0;
}
