#include <iostream>
using namespace std;

class Circulo {
public:
    double radio;

    double calcularArea() {
        const double PI = 3.14159;
        return PI * radio * radio;
    }

    double calcularPerimetro() {
        const double PI = 3.14159;
        return 2 * PI * radio;
    }

    void imprimir() {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Radio: " << radio << endl;
        cout << "Area: " << calcularArea() << endl;
        cout << "Perimetro: " << calcularPerimetro() << endl;
    }
};

int main() {
    Circulo c1;
    c1.radio = 5.0;
    c1.imprimir();

    Circulo c2;
    c2.radio = 3.0;
    c2.imprimir();

    return 0;
}
