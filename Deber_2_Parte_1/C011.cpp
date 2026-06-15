#include <iostream>
using namespace std;

class Rectangulo {
public:
    double base;
    double altura;

    Rectangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const {
        return base * altura;
    }

    double calcularPerimetro() const {
        return 2 * (base + altura);
    }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Base: " << base << ", Altura: " << altura << endl;
        cout << "Area: " << calcularArea() << endl;
        cout << "Perimetro: " << calcularPerimetro() << endl;
    }
};

int main() {
    Rectangulo r1(6.0, 4.0);
    Rectangulo r2(10.0, 2.5);
    r1.imprimir();
    r2.imprimir();
    return 0;
}
