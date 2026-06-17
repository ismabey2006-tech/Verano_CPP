#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* p = &x;

    cout << "x antes   : " << x << endl;
    *p = 50;
    cout << "x despues : " << x << endl;
    *p = 200;
    cout << "x final   : " << x << endl;

    return 0;
}
