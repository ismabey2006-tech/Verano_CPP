#include <iostream>
using namespace std;

class Base {
public:
    Base()  { cout << "Base creada" << endl; }
    ~Base() { cout << "Base destruida" << endl; }
};

class Derivada : public Base {
public:
    Derivada()  { cout << "Derivada creada" << endl; }
    ~Derivada() { cout << "Derivada destruida" << endl; }
};

int main() {
    // Salida a mano:
    // Base creada
    // Derivada creada
    // Derivada destruida
    // Base destruida
    Derivada d;
    return 0;
}
