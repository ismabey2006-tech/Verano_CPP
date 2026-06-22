#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Figura {
protected:
    string color;

public:
    Figura(string c) : color(c) {}
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual void imprimir() const {
        cout << "Figura " << color;
    }
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;
    static constexpr double PI = 3.14159;

public:
    Circulo(double r, string c) : Figura(c), radio(r > 0 ? r : 0) {}
    double calcularArea() const override { return PI * radio * radio; }
    double calcularPerimetro() const override { return 2 * PI * radio; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "Circulo " << color << " | Radio: " << radio
             << " | Area: " << calcularArea()
             << " | Perim: " << calcularPerimetro() << endl;
    }
};

class Rectangulo : public Figura {
private:
    double base, altura;

public:
    Rectangulo(double b, double h, string c)
        : Figura(c), base(b > 0 ? b : 0), altura(h > 0 ? h : 0) {}
    double calcularArea() const override { return base * altura; }
    double calcularPerimetro() const override { return 2 * (base + altura); }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "Rectangulo " << color << " | " << base << "x" << altura
             << " | Area: " << calcularArea()
             << " | Perim: " << calcularPerimetro() << endl;
    }
};

class Triangulo : public Figura {
private:
    double base, altura;

public:
    Triangulo(double b, double h, string c)
        : Figura(c), base(b > 0 ? b : 0), altura(h > 0 ? h : 0) {}
    double calcularArea() const override { return base * altura / 2.0; }
    double calcularPerimetro() const override { return 0.0; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "Triangulo " << color << " | Base: " << base
             << " Altura: " << altura << " | Area: " << calcularArea() << endl;
    }
};

int main() {
    Circulo c(5.0, "rojo");
    Rectangulo r(6.0, 4.0, "azul");
    Triangulo t(3.0, 4.0, "verde");

    c.imprimir();
    r.imprimir();
    t.imprimir();

    return 0;
}
