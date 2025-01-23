#include <iostream>
#include <windows.h>
using namespace std;
const int maksimal_antrian = 17;
bool keluar = false;
char ya_tidak;
int pilihan;
string data_masuk;
struct antrian
{
    int depan;
    int belakang;
    string nama[maksimal_antrian];
} mahasiswa;

void nilai_awal()
{
    mahasiswa.depan = -1;
    mahasiswa.belakang = -1;
}
int main()
{
}