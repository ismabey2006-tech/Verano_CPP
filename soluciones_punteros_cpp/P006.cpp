#include <iostream>
using namespace std;

int main() {
    // Fragmento B: correcto
    int x = 5;
    int* p = &x;
    cout << *p << endl;

    // Fragmento D: correcto
    *p = 100;
    cout << x << endl;

    // Los fragmentos A y C no se ejecutan aqui­ porque son problematicos:
    // A: int* p; cout << *p;  -> puntero salvaje, comportamiento indefinido.
    // C: p = 100;             -> conversion invalida/peligrosa de entero a puntero.

    return 0;
}
