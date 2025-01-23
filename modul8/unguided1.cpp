#include <iostream>
using namespace std;

struct dlinkedlist {
    dlinkedlist *prev;
    string data;
    dlinkedlist *next;
};

dlinkedlist *head;
dlinkedlist *tail;
dlinkedlist *vertex;

void inisialisasi() {
    head = NULL;
    tail = NULL;
}

bool dLinkKosong() {
    return (head == NULL && tail == NULL);
}

void tambahDepan(string dataUser) {
    if (dLinkKosong()) {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->prev = NULL;
        vertex->next = NULL;
        head = vertex;
        tail = vertex;
    } else {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->prev = NULL;
        vertex->next = NULL;
        vertex->next = head;
        head->prev = vertex;
        head = vertex;
    }
}

void tambahBelakang(string dataUser) {
    if (dLinkKosong()) {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->prev = NULL;
        vertex->next = NULL;
        head = vertex;
        tail = vertex;
    } else {
        vertex = new dlinkedlist;
        vertex->data = dataUser;
        vertex->prev = NULL;
        vertex->next = NULL;
        tail->next = vertex;
        vertex->prev = tail;
        tail = vertex;
    }
}

void hapusDepan() {
    if (dLinkKosong()) {
        cout << "Kosong...!!!" << endl;
    } else {
        dlinkedlist *helper;
        helper = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            head = head->next;
            head->prev = NULL;
            helper->next = NULL;
            delete helper;
        }
    }
}

void hapusBelakang() {
    if (dLinkKosong()) {
        cout << "Kosong...!!!" << endl;
    } else {
        if (head == tail) {
            dlinkedlist *helper;
            helper = head;
            head = NULL;
            tail = NULL;
            delete helper;
        } else {
            dlinkedlist *helper;
            helper = tail;
            tail = tail->prev;
            tail->next = NULL;
            helper->prev = NULL;
            delete helper;
        }
    }
}

void tampilData() {
    if (dLinkKosong()) {
        cout << "Kosong...!!!" << endl;
    } else {
        dlinkedlist *helper;
        helper = head;
        while (helper != NULL) {
            cout << helper->data << " ";
            helper = helper->next;
        }
    }
}

void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah Data di Depan\n";
    cout << "2. Tambah Data di Belakang\n";
    cout << "3. Hapus Data di Depan\n";
    cout << "4. Hapus Data di Belakang\n";
    cout << "5. Tampil Data\n";
    cout << "6. Keluar\n";
    cout << "Pilihan: ";
}

int main() {
    int pilihan;
    string data;
    
    inisialisasi();

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                tambahDepan(data);
                break;
            case 2:
                cout << "Masukkan data: ";
                cin >> data;
                tambahBelakang(data);
                break;
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5:
                cout << "Data: ";
                tampilData();
                cout << endl;
                break;
            case 6:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}
