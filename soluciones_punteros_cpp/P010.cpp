#include <iostream>
using namespace std;

void triplicar(int* n) {
    *n = *n * 3;
}

void elevarAlCuadrado(int* n) {
    *n = (*n) * (*n);
}

void resetear(int* n) {
    *n = 0;
}

int main() {
    int x = 4;
    int* p = &x;

    cout << "x inicial     : " << x << endl;

    triplicar(p);
    cout << "tras triplicar: " << x << endl;

    elevarAlCuadrado(p);
    cout << "tras cuadrado : " << x << endl;

    resetear(p);
    cout << "tras resetear : " << x << endl;

    return 0;
}
