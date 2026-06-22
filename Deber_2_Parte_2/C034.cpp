#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cuenta {
protected:
    string titular;
    double saldo;

public:
    Cuenta(string t, double s) : titular(t), saldo(s >= 0 ? s : 0) {}

    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }

    virtual void depositar(double monto) {
        if (monto <= 0) {
            cout << "Error: monto debe ser positivo." << endl;
            return;
        }
        saldo += monto;
        cout << fixed << setprecision(2);
        cout << "Deposito: $" << monto << ". Saldo: $" << saldo << endl;
    }

    virtual void retirar(double monto) {
        cout << fixed << setprecision(2);
        if (monto <= 0) {
            cout << "Error: monto debe ser positivo." << endl;
        } else if (monto <= saldo) {
            saldo -= monto;
            cout << "Retiro: $" << monto << ". Saldo: $" << saldo << endl;
        } else {
            cout << "Error: saldo insuficiente." << endl;
        }
    }

    virtual void imprimir() const {
        cout << fixed << setprecision(2);
        cout << titular << ": $" << saldo << endl;
    }

    virtual ~Cuenta() {}
};

class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;

public:
    CuentaAhorro(string t, double s, double tasa) : Cuenta(t, s), tasaInteres(tasa) {}

    void aplicarInteres() {
        saldo += saldo * tasaInteres;
        cout << fixed << setprecision(2);
        cout << "Interes aplicado. Saldo: $" << saldo << endl;
    }

    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "[Ahorro] " << titular << ": $" << saldo
             << " | Interes: " << tasaInteres * 100 << "%" << endl;
    }
};

class CuentaCorriente : public Cuenta {
private:
    double sobregiroMax;

public:
    CuentaCorriente(string t, double s, double sobregiro)
        : Cuenta(t, s), sobregiroMax(sobregiro >= 0 ? sobregiro : 0) {}

    void retirar(double monto) override {
        cout << fixed << setprecision(2);
        if (monto <= 0) {
            cout << "Error: monto debe ser positivo." << endl;
        } else if (monto <= saldo + sobregiroMax) {
            saldo -= monto;
            cout << "Retiro: $" << monto << ". Saldo: $" << saldo << endl;
        } else {
            cout << "Retiro: $" << monto << ". RECHAZADO: supera limite de sobregiro." << endl;
        }
    }

    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << "[Corriente] " << titular << ": $" << saldo
             << " | Sobregiro max: $" << sobregiroMax << endl;
    }
};

int main() {
    CuentaAhorro ahorro("Ana", 1000.0, 0.05);
    ahorro.imprimir();
    ahorro.depositar(200.0);
    ahorro.aplicarInteres();

    CuentaCorriente corriente("Luis", 500.0, 200.0);
    corriente.imprimir();
    corriente.retirar(600.0);
    corriente.retirar(200.0);

    return 0;
}
