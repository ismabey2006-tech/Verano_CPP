#include <iostream>
#include <iomanip>
using namespace std;

class Forma {
public:
    virtual double area() const = 0;
    void imprimir() const {
        cout << fixed << setprecision(2);
        cout << "Area: " << area() << endl;
    }
    virtual ~Forma() {}
};

class Cuadrado : public Forma {
private:
    double lado;

public:
    Cuadrado(double l) : lado(l) {}
    double area() const override { return lado * lado; }
};

class Rombo : public Forma {
private:
    double d1, d2;

public:
    Rombo(double a, double b) : d1(a), d2(b) {}
    double area() const override { return d1 * d2 / 2.0; }
};

class Pentagono : public Forma {
private:
    double perimetro, apotema;

public:
    Pentagono(double p, double a) : perimetro(p), apotema(a) {}
    double area() const override { return perimetro * apotema / 2.0; }
};

int main() {
    Forma* formas[3] = {
        new Cuadrado(5.0),
        new Rombo(6.0, 8.0),
        new Pentagono(21.0, 3.277142857)
    };

    for (int i = 0; i < 3; i++) {
        formas[i]->imprimir();
    }

    for (int i = 0; i < 3; i++) {
        delete formas[i];
        formas[i] = nullptr;
    }

    return 0;
}
