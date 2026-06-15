#include <iostream>
using namespace std;

class Rectangulo {
private:
    double base;
    double altura;

public:
    Rectangulo(double base, double altura) : base(1), altura(1) {
        setBase(base);
        setAltura(altura);
    }

    double getBase() const { return base; }
    double getAltura() const { return altura; }

    void setBase(double base) {
        if (base > 0) this->base = base;
        else cout << "Base debe ser positiva." << endl;
    }

    void setAltura(double altura) {
        if (altura > 0) this->altura = altura;
        else cout << "Altura debe ser positiva." << endl;
    }

    double calcularArea() const {
        return base * altura;
    }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Base: " << base << ", Altura: " << altura
             << ", Area: " << calcularArea() << endl;
    }
};

int main() {
    Rectangulo r(5.0, 3.0);
    r.imprimir();
    r.setBase(-2.0);
    r.imprimir();
    r.setBase(8.0);
    r.imprimir();
    return 0;
}
