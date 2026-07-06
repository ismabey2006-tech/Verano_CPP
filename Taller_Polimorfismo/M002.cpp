#include <iostream>
using namespace std;

/*
M002 | TRAZA — orden de destructores en jerarquia con heap

a) Salida completa:
   A construido
   B construido
   C construido
   ---
   ~C destruido
   ~B destruido
   ~A destruido

b) Antes del delete existen:
   - Un objeto C en heap, apuntado por A* obj.
   - Dentro de A: int[5], apuntado por datos.
   - Dentro de B: double[3], apuntado por vals.
   - Dentro de C: char[10], apuntado por buf.

c) Si ~A() no fuera virtual y haces delete obj usando A*, solo se llamaria
   ~A(). Quedarian sin liberar vals y buf, porque ~B() y ~C() no se ejecutan.

d) Construccion: A -> B -> C.
   Destruccion: C -> B -> A.
   Si, se cumple LIFO porque se destruye en orden inverso a la construccion.
*/

class A {
private:
    int* datos;

public:
    A() {
        datos = new int[5];
        cout << "A construido" << endl;
    }

    virtual ~A() {
        delete[] datos;
        datos = nullptr;
        cout << "~A destruido" << endl;
    }
};

class B : public A {
private:
    double* vals;

public:
    B() : A() {
        vals = new double[3];
        cout << "B construido" << endl;
    }

    ~B() override {
        delete[] vals;
        vals = nullptr;
        cout << "~B destruido" << endl;
    }
};

class C : public B {
private:
    char* buf;

public:
    C() : B() {
        buf = new char[10];
        cout << "C construido" << endl;
    }

    ~C() override {
        delete[] buf;
        buf = nullptr;
        cout << "~C destruido" << endl;
    }
};

int main() {
    A* obj = new C();
    cout << "---" << endl;
    delete obj;
    obj = nullptr;
    return 0;
}
