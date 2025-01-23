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

void tampil_data()
{
    if (simpul_kosong())
    {
        cout << "Tidak ada data" << endl;
    }
    else
    {
        linkedlist *helper;
        helper = head;
        while (helper != NULL)
        {
            cout << helper->data << " ";
            helper = helper->next;
        }
    }
}

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
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
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
        simpul = new linkedlist;
        simpul->data = data_user;
        simpul->next = head;
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
        linkedlist *helper;
        helper = head;
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
        linkedlist *helper;
        helper = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            delete helper;
        }
        else
        {
            head = head->next;
            helper->next = NULL;
            delete helper;
        }
    }
}

int main()
{
    inisialisasi();
    tambah_depan("Rabu");
    tambah_belakang("Kamis");
    tambah_depan("Selasa");
    hapus_belakang();
    tampil_data();
    return 0;
}