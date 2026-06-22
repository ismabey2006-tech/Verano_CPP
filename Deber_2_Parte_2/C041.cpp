#include <iostream>
using namespace std;

class Base {
public:
    void mostrar() { cout << "Base" << endl; }
    virtual ~Base() {}
};

class Derivada : public Base {
public:
    void mostrar() { cout << "Derivada" << endl; }
};

class BaseV {
public:
    virtual void mostrar() { cout << "DerivadaV solo se imprime si hay virtual" << endl; }
    virtual ~BaseV() {}
};

class DerivadaV : public BaseV {
public:
    void mostrar() override { cout << "DerivadaV" << endl; }
};

int main() {
    Base* p1 = new Derivada();
    BaseV* p2 = new DerivadaV();

    cout << "Linea A: ";
    p1->mostrar();
    cout << "Linea B: ";
    p2->mostrar();

    delete p1;
    delete p2;
    p1 = nullptr;
    p2 = nullptr;

    return 0;
}
