#include <iostream>
using namespace std;

int main() {
    int x = 5, y = 10, z = 15;
    int* p = &x;

    cout << "p -> x: *p=" << *p << " x=" << x << endl;
    *p = 99;
    cout << "Modificar *p=99: x=" << x << endl;

    p = &y;
    cout << "p -> y: *p=" << *p << " y=" << y << endl;
    *p = 88;
    cout << "Modificar *p=88: y=" << y << endl;

    p = &z;
    cout << "p -> z: *p=" << *p << " z=" << z << endl;
    *p = 77;
    cout << "Modificar *p=77: z=" << z << endl;

    return 0;
}

