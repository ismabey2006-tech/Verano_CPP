#include <iostream>
using namespace std;

void imprimirValor(int* p) {
    if (p == NULL) {
        cout << "Puntero nulo - sin valor" << endl;
    } else {
        cout << "Valor: " << *p << endl;
    }
}

int main() {
    int x = 55;
    int* p = &x;
    int* n = NULL;

    imprimirValor(p);
    imprimirValor(n);

    return 0;
}

//Por temas de mi version de Dev-C++, use NULL en vez de nulllptr, pero hacen exactamente lo mismo.
