#include <iostream>
using namespace std;

class Circulo {
public:
    const double PI;
    double radio;

    Circulo(double r) : PI(3.14159), radio(r) {}

    double area() const {
        return PI * radio * radio;
    }

    double perimetro() const {
        return 2 * PI * radio;
    }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Radio: " << radio << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
    }
};

int main() {
    Circulo c(7.0);
    c.imprimir();
    return 0;
}
