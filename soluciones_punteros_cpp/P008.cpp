#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int* p = &x;
    int** pp = &p;

    cout << "x    = " << x << endl;
    cout << "*p   = " << *p << endl;
    cout << "**pp = " << **pp << endl;

    cout << "dir x via &x : " << &x << endl;
    cout << "dir x via p  : " << p << endl;
    cout << "dir x via *pp: " << *pp << endl;

    cout << "dir p via &p : " << &p << endl;
    cout << "dir p via pp : " << pp << endl;

    **pp = 99;
    cout << "x despues de **pp=99: " << x << endl;

    return 0;
}
