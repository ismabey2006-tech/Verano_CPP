#include <iostream>
#include <cmath>
using namespace std;

class Punto {
public:
    double x;
    double y;

    void imprimir() {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "(" << x << ", " << y << ")";
    }

    double distanciaA(Punto otro) {
        return sqrt((x - otro.x) * (x - otro.x) + (y - otro.y) * (y - otro.y));
    }

    Punto puntoMedio(Punto otro) {
        Punto medio;
        medio.x = (x + otro.x) / 2.0;
        medio.y = (y + otro.y) / 2.0;
        return medio;
    }
};

int main() {
    Punto p1;
    p1.x = 3.0; p1.y = 4.0;
    Punto p2;
    p2.x = 7.0; p2.y = 1.0;

    cout << "P1: "; p1.imprimir(); cout << endl;
    cout << "P2: "; p2.imprimir(); cout << endl;
    cout << "Distancia: " << p1.distanciaA(p2) << endl;
    Punto medio = p1.puntoMedio(p2);
    cout << "Punto medio: "; medio.imprimir(); cout << endl;
    return 0;
}
