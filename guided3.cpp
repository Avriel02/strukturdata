#include <iostream>
using namespace std;

int main()
{

    // true || (false && !true) || false
    // true || (false && false) || false
    // true || false || false
    // true || false
    // true

    bool benar = true;
    bool salah = false;
    bool nilaiKebenaran;

    nilaiKebenaran = benar || (salah && !benar) || salah;
    cout << nilaiKebenaran << endl;

    // !false && true || (false && true) || !false
    // true && true || (false && true) || true
    // true || false || true
    // true || true
    // true

    // nilai kebenaran = benar || (salah && !benar) salah;
    nilaiKebenaran = !salah && benar || (salah && benar) || salah;
    cout << nilaiKebenaran << endl;
    return 0;
}