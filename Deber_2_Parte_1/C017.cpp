#include <iostream>
#include <cmath>
using namespace std;

class Punto {
public:
    double x;
    double y;

    Punto(double a, double b) : x(a), y(b) {}

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "(" << x << ", " << y << ")";
    }

    double distanciaA(Punto otro) const {
        return sqrt((x - otro.x) * (x - otro.x) + (y - otro.y) * (y - otro.y));
    }
};

class Segmento {
private:
    Punto inicio;
    Punto fin;

public:
    Segmento(Punto p1, Punto p2) : inicio(p1), fin(p2) {}

    double longitud() const {
        return inicio.distanciaA(fin);
    }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Inicio: "; inicio.imprimir(); cout << endl;
        cout << "Fin   : "; fin.imprimir(); cout << endl;
        cout << "Longitud: " << longitud() << endl;
    }
};

int main() {
    Punto p1(0, 0);
    Punto p2(3, 4);
    Segmento s(p1, p2);
    s.imprimir();
    return 0;
}
