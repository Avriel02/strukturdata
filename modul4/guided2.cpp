#include <iostream>
using namespace std;
struct H
{
    string Nama_Hewan, Cara_Berkembangbiak, Alat_Pernafasan, Tempat_Hidup;
    char Jenis_Kelamin;
    bool apakah_Karnivora;
};
struct HD
{
    int jumlah_kaki;
    bool apakah_menyusui;
    string suara;
    H darat;
};
struct HL
{
    string bentuk_sirip;
    string pertahanan_diri;
    HD laut;
};

int main()
{
    struct HD Sapi;
    Sapi.darat.Nama_Hewan = "sapi";
    Sapi.darat.Jenis_Kelamin = 'L';
    Sapi.darat.Cara_Berkembangbiak = "melahirkan";
    Sapi.darat.Alat_Pernafasan = "paru-paru";
    Sapi.darat.Tempat_Hidup = "darat";
    Sapi.darat.apakah_Karnivora = false;
    Sapi.jumlah_kaki = 4;
    Sapi.apakah_menyusui = true;
    Sapi.suara = "mberrr";

    cout << "=========================================" << endl;
    cout << "Nama Hewan = " << Sapi.darat.Nama_Hewan << endl;
    cout << "Jenis Kelamin = " << Sapi.darat.Jenis_Kelamin << endl;
    cout << "Cara berkembangbiak = " << Sapi.darat.Cara_Berkembangbiak << endl;
    cout << "Alat Pernafasan = " << Sapi.darat.Alat_Pernafasan << endl;
    cout << "Tempat Hidup = " << Sapi.darat.Tempat_Hidup << endl;
    if (Sapi.darat.apakah_Karnivora)
        cout << "Apakah Karnivora = iya" << endl;
    else
        cout << "Apakah Karnivora = tidak" << endl;
    cout << "Jumlah Kaki = " << Sapi.jumlah_kaki << endl;
    if (Sapi.apakah_menyusui)
        cout << "Apakah Menyusui = iya" << endl;
    else
        cout << "Apakah Menyusui = tidak" << endl;
    cout << "Suara = " << Sapi.suara << endl;

    struct HL Udang;
    Udang.laut.darat.Nama_Hewan = "Udang";
    Udang.laut.darat.Jenis_Kelamin = 'P';
    Udang.laut.darat.Cara_Berkembangbiak = "Bertelur";
    Udang.laut.darat.Alat_Pernafasan = "insang";
    Udang.laut.darat.Tempat_Hidup = "Laut";
    Udang.laut.darat.apakah_Karnivora = false;
    Udang.bentuk_sirip = "tidak ada sirip";
    Udang.pertahanan_diri = "lapisan mukus";
    cout << "=========================================" << endl;
    cout << "Nama Hewan = " << Udang.laut.darat.Nama_Hewan << endl;
    cout << "Jenis Kelamin = " << Udang.laut.darat.Jenis_Kelamin << endl;
    cout << "Cara Berkembang biak = " << Udang.laut.darat.Cara_Berkembangbiak << endl;
    cout << "Alat Pernafasan = " << Udang.laut.darat.Alat_Pernafasan << endl;
    cout << "Tempat Hidup = " << Udang.laut.darat.Tempat_Hidup << endl;
    if (Udang.laut.darat.apakah_Karnivora)
        cout << "Apakah Karnivora = iya" << endl;
    else
        cout << "Apakah Karnivora = tidak" << endl;
    cout << "Bentuk Sirip = " << Udang.bentuk_sirip << endl;
    cout << "Bentuk Pertahanan Diri = " << Udang.pertahanan_diri << endl;
}