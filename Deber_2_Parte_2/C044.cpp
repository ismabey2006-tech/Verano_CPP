#include <iostream>
using namespace std;

class BaseSinVirtual {
public:
    BaseSinVirtual() { cout << "Base creada" << endl; }
    ~BaseSinVirtual() { cout << "Base destruida" << endl; }
};

class DerivadaSinVirtual : public BaseSinVirtual {
public:
    DerivadaSinVirtual() { cout << "Derivada creada" << endl; }
    ~DerivadaSinVirtual() { cout << "Derivada destruida" << endl; }
};

class BaseConVirtual {
public:
    BaseConVirtual() { cout << "Base creada" << endl; }
    virtual ~BaseConVirtual() { cout << "Base destruida" << endl; }
};

class DerivadaConVirtual : public BaseConVirtual {
public:
    DerivadaConVirtual() { cout << "Derivada creada" << endl; }
    ~DerivadaConVirtual() override { cout << "Derivada destruida" << endl; }
};

int main() {
    cout << "Version SIN destructor virtual:" << endl;
    BaseSinVirtual* p1 = new DerivadaSinVirtual();
    delete p1; // En la practica solo se llama ~BaseSinVirtual; es comportamiento peligroso.

    cout << endl << "Version CON destructor virtual:" << endl;
    BaseConVirtual* p2 = new DerivadaConVirtual();
    delete p2;

    cout << endl;
    cout << "La palabra que arregla el problema es: virtual" << endl;
    return 0;
}
