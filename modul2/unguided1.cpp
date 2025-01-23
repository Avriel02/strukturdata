#include <iostream>
#include <string>

using namespace std;

int main()
{

    string dosen_si[10] = {
        "M. Yoka Fathoni, S.Kom.,M.Kom",
        "Sarah Astiti, S.Kom.,M.MT",
        "Sukmadiningtyas, S.Kom.,M.Kom",
        "Khairun Nisa Meiah Ngafidin, S.Pd.,M.Kom",
        "Toni Anwar, S.Kom.,M.MSi",
        "Sandhy Fernandez, S.Kom.,M.Kom",
        "Sena Wijayanto,S.Pd.,M.T",
        "Mahazzam Afrad, S.Kom., M.Kom",
        "Muhamad Awiet Wiedanto Prasetyo, S.Kom.,M.MSI",
        "Cepi Ramdani, S.Kom.,M.Eng"};

    string *pointer_dosensi = dosen_si;

    cout << "Alamat memori dari variabel dosen_si:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Alamat memori indeks " << i << ": " << (pointer_dosensi + i) << endl;
    }

    cout << "\nNilai dari variabel dosen_si melalui pointer_dosensi:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ". " << *(pointer_dosensi + i) << endl;
    }

    *(pointer_dosensi + 0) = "Resad Setyadi,S.T.,S.Si.,MMSI";
    *(pointer_dosensi + 1) = "Yudha Saintika, S.T.,M.T.I";

        cout << "\nSetelah perubahan, nilai dari variabel dosen_si:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ". " << *(pointer_dosensi + i) << endl;
    }

    return 0;
}
