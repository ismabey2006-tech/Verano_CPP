#include <iostream>
#include <cmath>
using namespace std;

class Triangulo {
private:
    double base;
    double altura;
    double hipotenusa;

public:
    Triangulo(double b, double h) : base(b), altura(h) {
        hipotenusa = sqrt(base * base + altura * altura);
    }

    double getBase() const { return base; }
    double getAltura() const { return altura; }
    double getHipotenusa() const { return hipotenusa; }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Base     : " << base << endl;
        cout << "Altura   : " << altura << endl;
        cout << "Hipotenusa: " << hipotenusa << endl;
    }
};

int main() {
    Triangulo t(3, 4);
    t.imprimir();
    return 0;
}
