#include <iostream>
using namespace std;

int main() {
    int valor = 25;
    int* ptr = &valor;

    cout << "Valor     : " << valor << endl;
    cout << "Direccion : " << &valor << endl;
    cout << "ptr guarda: " << ptr << endl;
    cout << "*ptr      : " << *ptr << endl;

    return 0;
}
