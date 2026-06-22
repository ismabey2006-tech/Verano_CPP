#include <iostream>
#include <iomanip>
using namespace std;

class Figura {
protected:
    double area;

public:
    Figura(double a) : area(a) {}
    virtual void imprimir() const {
        cout << fixed << setprecision(2);
        cout << "Figura: " << area << endl;
    }
    virtual ~Figura() {}
};

class Rectangulo : public Figura {
protected:
    double base;
    double altura;

public:
    Rectangulo(double b, double h) : Figura(b * h), base(b), altura(h) {}

    void imprimir() const override {
        Figura::imprimir();
        cout << "Base: " << base << " Altura: " << altura << endl;
    }
};

class Cuadrado : public Rectangulo {
private:
    double lado;

public:
    Cuadrado(double l) : Rectangulo(l, l), lado(l) {}

    void imprimir() const override {
        Rectangulo::imprimir();
        cout << "Lado: " << lado << endl;
    }
};

int main() {
    Cuadrado c(5.0);
    c.imprimir();
    return 0;
}
