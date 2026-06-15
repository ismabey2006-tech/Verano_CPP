#include <iostream>
#include <cmath>
using namespace std;

class Triangulo {
public:
    double lado1;
    double lado2;
    double lado3;

    double calcularPerimetro() {
        return lado1 + lado2 + lado3;
    }

    double calcularArea() {
        double s = calcularPerimetro() / 2.0;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }

    bool esEquilatero() {
        return lado1 == lado2 && lado2 == lado3;
    }

    bool esRectangulo() {
        double a = lado1;
        double b = lado2;
        double c = lado3;


        if (a > b) { double temp = a; a = b; b = temp; }
        if (b > c) { double temp = b; b = c; c = temp; }
        if (a > b) { double temp = a; a = b; b = temp; }

        double diferencia = (a*a + b*b) - c*c;
        if (diferencia < 0) diferencia = -diferencia;
        return diferencia < 0.0001;
    }

    void imprimir() {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Lados: " << lado1 << ", " << lado2 << ", " << lado3 << endl;
        cout << "Perimetro: " << calcularPerimetro() << endl;
        cout << "Area: " << calcularArea() << endl;
        cout << "Equilatero: " << (esEquilatero() ? "SI" : "NO") << endl;
        cout << "Rectangulo: " << (esRectangulo() ? "SI" : "NO") << endl;
    }
};

int main() {
    Triangulo t;
    t.lado1 = 3.0;
    t.lado2 = 4.0;
    t.lado3 = 5.0;
    t.imprimir();
    return 0;
}
