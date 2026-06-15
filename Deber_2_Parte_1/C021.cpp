#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;

public:
    CuentaBancaria(string t, double s) : titular(t) {
        saldo = (s >= 0) ? s : 0;
    }

    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }

    void depositar(double monto) {
        cout.setf(ios::fixed);
        cout.precision(2);
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito: $" << monto << ". Saldo: $" << saldo << endl;
        } else {
            cout << "Error: monto debe ser positivo." << endl;
        }
    }

    void retirar(double monto) {
        cout.setf(ios::fixed);
        cout.precision(2);
        if (monto <= 0) {
            cout << "Error: monto debe ser positivo." << endl;
        } else if (monto <= saldo) {
            saldo -= monto;
            cout << "Retiro: $" << monto << ". Saldo: $" << saldo << endl;
        } else {
            cout << "Error: saldo insuficiente." << endl;
        }
    }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << titular << ": $" << saldo << endl;
    }
};

int main() {
    CuentaBancaria cuenta("Ana Torres", -100.0);
    cuenta.imprimir();
    cuenta.depositar(500.0);
    cuenta.retirar(200.0);
    cuenta.retirar(500.0);
    cuenta.depositar(-10.0);
    cuenta.imprimir();
    return 0;
}
