#include <iostream>
using namespace std;

int main(){
    int x = 42;
    int* p = &x;

    cout << "Valor de x: " << x << endl;
    cout << "Direccion de x: " << &x << endl;
    cout << "Valor de p: " << p << endl;
    cout << "Valor de *p: " << *p << endl;

    return 0;
}
