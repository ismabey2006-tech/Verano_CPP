#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int stock;

public:
    Producto(string n, double p, int s) : nombre(n) {
        precio = (p >= 0) ? p : 0;
        stock = (s >= 0) ? s : 0;
    }

    Producto(string n, double p) : nombre(n) {
        precio = (p >= 0) ? p : 0;
        stock = 0;
    }

    ~Producto() {
        cout << "Producto " << nombre << " eliminado del sistema." << endl;
    }

    void vender(int cantidad) {
        if (cantidad > 0 && cantidad <= stock) {
            stock -= cantidad;
            cout << "Venta exitosa. Stock restante: " << stock << endl;
        } else {
            cout << "Stock insuficiente." << endl;
        }
    }

    void reabastecer(int cantidad) {
        if (cantidad > 0) stock += cantidad;
        cout << "Reabastecer: " << cantidad << " unidades. Stock: " << stock << endl;
    }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << nombre << " | $" << precio << " | Stock: " << stock << endl;
    }
};

int main() {
    Producto p("Laptop", 1200.0, 5);
    p.imprimir();
    p.vender(2);
    p.vender(10);
    p.reabastecer(10);
    p.imprimir();
    return 0;
}
