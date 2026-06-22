#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Figura {
public:
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual void imprimir() const {
        cout << fixed << setprecision(2);
        cout << "Area: " << calcularArea()
             << " | Perimetro: " << calcularPerimetro() << endl;
    }
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;
    static constexpr double PI = 3.14159;

public:
    Circulo(double r) : radio(r > 0 ? r : 0) {}
    double calcularArea() const override { return PI * radio * radio; }
    double calcularPerimetro() const override { return 2 * PI * radio; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "Circulo r=" << radio << " | Area: " << calcularArea()
             << " | Perimetro: " << calcularPerimetro() << endl;
    }
};

class Rectangulo : public Figura {
private:
    double base, altura;

public:
    Rectangulo(double b, double h) : base(b > 0 ? b : 0), altura(h > 0 ? h : 0) {}
    double calcularArea() const override { return base * altura; }
    double calcularPerimetro() const override { return 2 * (base + altura); }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "Rectangulo " << base << "x" << altura << " | Area: " << calcularArea()
             << " | Perimetro: " << calcularPerimetro() << endl;
    }
};

class Triangulo : public Figura {
private:
    double a, b, c;

public:
    Triangulo(double l1, double l2, double l3) : a(l1), b(l2), c(l3) {}
    double calcularArea() const override {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double calcularPerimetro() const override { return a + b + c; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "Triangulo " << a << "," << b << "," << c << " | Area: " << calcularArea()
             << " | Perimetro: " << calcularPerimetro() << endl;
    }
};

int main() {
    Figura* figuras[5] = {
        new Circulo(5.0),
        new Rectangulo(6.0, 4.0),
        new Triangulo(3.0, 4.0, 5.0),
        new Circulo(2.0),
        new Rectangulo(3.0, 7.0)
    };

    double areaTotal = 0;
    for (int i = 0; i < 5; i++) {
        figuras[i]->imprimir();
        areaTotal += figuras[i]->calcularArea();
    }

    cout << fixed << setprecision(2);
    cout << "Area total: " << areaTotal << endl;

    for (int i = 0; i < 5; i++) {
        delete figuras[i];
        figuras[i] = nullptr;
    }

    return 0;
}
