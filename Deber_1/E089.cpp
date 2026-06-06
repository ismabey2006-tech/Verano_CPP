#include <iostream>
#include <iomanip>
using namespace std;

class Rectangulo{
private:
    double base;
    double altura;

public:
    Rectangulo(double b, double h){
        base = b;
        altura = h;
    }

    double calcularArea(){
        return base * altura;
    }

    double calcularPerimetro(){
        return 2 * (base + altura);
    }

    void imprimir(){
        cout << fixed << setprecision(2);
        cout << "Rectangulo: base=" << base << ", altura=" << altura << endl;
        cout << "Area: " << calcularArea() << endl;
        cout << "Perimetro: " << calcularPerimetro() << endl;
    }
};

int main(){
    double base, altura;

    cin >> base >> altura;

    Rectangulo r(base, altura);
    r.imprimir();

    return 0;
}
