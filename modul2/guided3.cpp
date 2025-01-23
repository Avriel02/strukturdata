#include <iostream>
using namespace std;

int main()
{
    int jumlah = 30;
    string negara = "Indonesia";
    float volume = 17.25;
    bool sehat = true;

    int *pointerJ;
    string *pointerN;
    float *pointerV;
    bool *pointerS;

    pointerJ = &jumlah;
    pointerN = &negara;
    pointerV = &volume;
    pointerS = &sehat;

    cout << "value awal Jumlah: " << jumlah << endl;
    *pointerJ = 191;
    cout << "value terbaru jumlah: " << jumlah << endl;
    cout << "value awal negara: " << negara << endl;
    *pointerN = "England";
    cout << "value terbaru negara: " << negara << endl;
    cout << "value awal volume: " << volume << endl;
    *pointerV = 0.125;
    cout << "value terbaru volume: " << volume << endl;
    cout << "value awal sehat: " << sehat << endl;
    *pointerS = false;
    cout << "value terbaru sehat: " << sehat << endl;

    return 0;
}