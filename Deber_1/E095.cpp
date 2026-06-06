#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Figura{
public:
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() = 0;
};

class Circulo : public Figura{
private:
    double radio;
    const double PI = 3.14159;

public:
    Circulo(double r){
        radio = r;
    }

    double calcularArea(){
        return PI * radio * radio;
    }

    double calcularPerimetro(){
        return 2 * PI * radio;
    }

    void describir(){
        cout << fixed << setprecision(2);
        cout << "Circulo (r=" << radio << "): Area=" << calcularArea() << ", Perimetro=" << calcularPerimetro() << endl;
    }
};

class Triangulo : public Figura{
private:
    double a;
    double b;
    double c;

public:
    Triangulo(double ladoA, double ladoB, double ladoC){
        a = ladoA;
        b = ladoB;
        c = ladoC;
    }

    double calcularArea(){
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double calcularPerimetro(){
        return a + b + c;
    }

    void describir(){
        cout << fixed << setprecision(2);
        cout << "Triangulo (" << a << "," << b << "," << c << "): Area=" << calcularArea() << ", Perimetro=" << calcularPerimetro() << endl;
    }
};

int main(){
    double radio, a, b, c;

    cin >> radio;
    cin >> a >> b >> c;

    Circulo circulo(radio);
    Triangulo triangulo(a, b, c);

    circulo.describir();
    triangulo.describir();

    return 0;
}
