#include <iostream>
using namespace std;

int main() {
    int a = 1;
    int b = 2;
    int* p = &a;

    cout << *p << endl;    // 1
    *p = 10;               // a cambia a 10
    cout << a << endl;     // 10
    p = &b;                // p ahora apunta a b
    cout << *p << endl;    // 2
    *p = *p + 5;           // b cambia a 7
    cout << b << endl;     // 7
    cout << a << endl;     // 10

    return 0;
}
