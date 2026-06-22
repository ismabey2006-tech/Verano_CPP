#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Figura {
public:
    virtual double area() const = 0;
    virtual void imprimir() const = 0;
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;
    string color;
    static constexpr double PI = 3.14159;

public:
    Circulo(double r, string c) : radio(r), color(c) {}
    double area() const override { return PI * radio * radio; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "Circulo (r=" << radio << "): Area=" << area() << endl;
    }
};

class Rectangulo : public Figura {
private:
    double base, altura;
    string color;

public:
    Rectangulo(double b, double h, string c) : base(b), altura(h), color(c) {}
    double area() const override { return base * altura; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "Rect (" << base << "x" << altura << "): Area=" << area() << endl;
    }
};

Figura* crearFigura(string tipo, double a, double b) {
    if (tipo == "circulo") return new Circulo(a, "rojo");
    if (tipo == "rectangulo") return new Rectangulo(a, b, "azul");
    return nullptr;
}

int main() {
    string tipo;
    double a, b;

    cout << "Ingrese figuras como: tipo a b. Ejemplo: circulo 5 0" << endl;
    cout << "Si no ingresa datos, se usan ejemplos por defecto." << endl;

    Figura* figuras[2] = {nullptr, nullptr};
    int cantidad = 0;

    while (cantidad < 2 && (cin >> tipo >> a >> b)) {
        Figura* f = crearFigura(tipo, a, b);
        if (f != nullptr) figuras[cantidad++] = f;
    }

    if (cantidad == 0) {
        figuras[cantidad++] = crearFigura("circulo", 5.0, 0.0);
        figuras[cantidad++] = crearFigura("rectangulo", 6.0, 4.0);
    }

    for (int i = 0; i < cantidad; i++) {
        figuras[i]->imprimir();
    }

    for (int i = 0; i < cantidad; i++) {
        delete figuras[i];
        figuras[i] = nullptr;
    }

    return 0;
}
