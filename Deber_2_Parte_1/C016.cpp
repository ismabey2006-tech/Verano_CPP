#include <iostream>
using namespace std;

class Fecha {
public:
    int dia;
    int mes;
    int anio;

    Fecha() : dia(1), mes(1), anio(2000) {}
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}
    Fecha(int d, int m) : dia(d), mes(m), anio(2024) {}

    void imprimir() const {
        if (dia < 10) cout << "0";
        cout << dia << "/";
        if (mes < 10) cout << "0";
        cout << mes << "/" << anio << endl;
    }
};

int main() {
    Fecha f1;
    Fecha f2(15, 6, 1999);
    Fecha f3(22, 3);
    f1.imprimir();
    f2.imprimir();
    f3.imprimir();
    return 0;
}
