#include <iostream>
using namespace std;

int main () {

    int a = 10;
    int b;

    int *c = &a;
    int  d  = *c;

    cout << "alamat a : " << &a << endl;
    cout << "alamat b : " << &b << endl;
    cout << "c : "        << c  << endl;

    return 0;
}