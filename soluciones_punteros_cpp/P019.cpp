#include <iostream>
using namespace std;

int main() {
    // Este archivo es solo demostrativo de correcciones seguras.

    // A corregido: inicializar antes de desreferenciar.
    int* a = new int(42);
    delete a;
    a = nullptr;

    // B corregido: liberar antes de reasignar.
    int* b = new int(10);
    delete b;
    b = new int(20);
    delete b;
    b = nullptr;

    // C corregido: no usar después de delete.
    int* c = new int(5);
    delete c;
    c = nullptr;

    // D corregido: new[] se libera con delete[].
    int* arr = new int[10];
    delete[] arr;
    arr = nullptr;

    // E corregido: liberar una sola vez el objeto compartido.
    int* p1 = new int(5);
    int* p2 = p1;
    delete p1;
    p1 = nullptr;
    p2 = nullptr;

    // F corregido: si se retorna puntero, usar heap.
    // El caller debe liberar con delete.
    int* f = new int(99);
    cout << *f << endl;
    delete f;
    f = nullptr;

    return 0;
}
