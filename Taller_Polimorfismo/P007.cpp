#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

class Figura {
public:
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void imprimir() const = 0;
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double radio) : radio(radio) {}

    double area() const override {
        return PI * radio * radio;
    }

    double perimetro() const override {
        return 2.0 * PI * radio;
    }

    void imprimir() const override {
        cout << left << setw(11) << "Circulo" << ": area="
             << fixed << setprecision(2) << area()
             << "  perim=" << perimetro() << endl;
    }
};

class Cuadrado : public Figura {
private:
    double lado;

public:
    Cuadrado(double lado) : lado(lado) {}

    double area() const override {
        return lado * lado;
    }

    double perimetro() const override {
        return 4.0 * lado;
    }

    void imprimir() const override {
        cout << left << setw(11) << "Cuadrado" << ": area="
             << fixed << setprecision(2) << area()
             << "  perim=" << perimetro() << endl;
    }
};

class TrianguloR : public Figura {
private:
    double cateto1;
    double cateto2;
    double hipotenusa;

public:
    TrianguloR(double cateto1, double cateto2)
        : cateto1(cateto1), cateto2(cateto2),
          hipotenusa(sqrt(cateto1 * cateto1 + cateto2 * cateto2)) {}

    double area() const override {
        return cateto1 * cateto2 / 2.0;
    }

    double perimetro() const override {
        return cateto1 + cateto2 + hipotenusa;
    }

    void imprimir() const override {
        cout << left << setw(11) << "TrianguloR" << ": area="
             << fixed << setprecision(2) << area()
             << "  perim=" << perimetro() << endl;
    }
};

int main() {
    Figura* figuras[5];
    figuras[0] = new Circulo(5.0);
    figuras[1] = new Cuadrado(5.0);
    figuras[2] = new TrianguloR(3.0, 4.0);
    figuras[3] = new Circulo(2.0);
    figuras[4] = new Cuadrado(3.0);

    for (int i = 0; i < 5; ++i) {
        figuras[i]->imprimir();
    }

    for (int i = 0; i < 5; ++i) {
        delete figuras[i];
        figuras[i] = nullptr;
    }

    return 0;
}
