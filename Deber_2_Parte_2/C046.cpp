#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Figura {
protected:
    string nombre;

public:
    Figura(string n) : nombre(n) {}
    virtual double calcularArea() const = 0;
    virtual void imprimir() const {
        cout << nombre;
    }
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;
    static constexpr double PI = 3.14159;

public:
    Circulo(double r) : Figura("Circulo"), radio(r) {}
    double calcularArea() const override { return PI * radio * radio; }
    void imprimir() const override { cout << "Circulo radio=" << radio; }
};

class Rectangulo : public Figura {
private:
    double base, altura;

public:
    Rectangulo(double b, double h) : Figura("Rectangulo"), base(b), altura(h) {}
    double calcularArea() const override { return base * altura; }
    void imprimir() const override { cout << "Rectangulo " << base << "x" << altura; }
};

class Triangulo : public Figura {
private:
    double base, altura;

public:
    Triangulo(double b, double h) : Figura("Triangulo"), base(b), altura(h) {}
    double calcularArea() const override { return base * altura / 2.0; }
    void imprimir() const override { cout << "Triangulo base=" << base << " altura=" << altura; }
};

void describir(const Figura& f) {
    cout << fixed << setprecision(2);
    f.imprimir();
    cout << " | Area: " << f.calcularArea() << endl;
}

int main() {
    Circulo c(5.0);
    Rectangulo r(6.0, 4.0);
    Triangulo t(3.0, 4.0);

    describir(c);
    describir(r);
    describir(t);

    return 0;
}
