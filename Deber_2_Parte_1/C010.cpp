#include <iostream>
#include <string>
using namespace std;

class Cuenta {
public:
    string titular;
    double saldo;

    void depositar(double monto) {
        saldo += monto;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Deposito: $" << monto << " | Nuevo saldo: $" << saldo << endl;
    }

    void retirar(double monto) {
        cout.setf(ios::fixed);
        cout.precision(2);
        if (tieneSaldo(monto)) {
            saldo -= monto;
            cout << "Retiro: $" << monto << " | Nuevo saldo: $" << saldo << endl;
        } else {
            cout << "Saldo insuficiente." << endl;
        }
    }

    void imprimir() {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Titular: " << titular << " | Saldo: $" << saldo << endl;
    }

    bool tieneSaldo(double monto) {
        return saldo >= monto;
    }
};

int main() {
    Cuenta c;
    c.titular = "Ana Torres";
    c.saldo = 500.0;

    c.imprimir();
    c.depositar(200.0);
    c.retirar(100.0);
    c.retirar(1000.0);
    c.imprimir();

    return 0;
}
