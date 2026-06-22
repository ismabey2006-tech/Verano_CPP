#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cuenta {
private:
    string numeroCuenta;
    string titular;
    double saldo;

protected:
    void setSaldoInterno(double s) { saldo = s; }

public:
    Cuenta(string n, string t, double s) : numeroCuenta(n), titular(t), saldo(s >= 0 ? s : 0) {}
    string getNumeroCuenta() const { return numeroCuenta; }
    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }
    virtual string getTipo() const = 0;
    virtual double calcularInteres() const = 0;
    virtual void depositar(double monto) { if(monto > 0) saldo += monto; }
    virtual void retirar(double monto) { if(monto > 0 && monto <= saldo) saldo -= monto; }
    void imprimir() const {
        cout << fixed << setprecision(2);
        cout << getTipo() << " [" << numeroCuenta << "] " << titular
             << " | Saldo: $" << saldo << " | Interes estimado: $" << calcularInteres() << endl;
    }
    virtual ~Cuenta() {}
};

class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;
    double saldoMinimo;
public:
    CuentaAhorro(string n, string t, double s, double tasa, double min)
        : Cuenta(n,t,s), tasaInteres(tasa), saldoMinimo(min) {}
    string getTipo() const override { return "Ahorro"; }
    double calcularInteres() const override { return getSaldo() * tasaInteres; }
    void retirar(double monto) override {
        if(monto > 0 && getSaldo() - monto >= saldoMinimo) setSaldoInterno(getSaldo() - monto);
        else cout << "Retiro rechazado en ahorro: saldo minimo." << endl;
    }
};

class CuentaCorriente : public Cuenta {
private:
    double limiteCredito;
    double cargoMensual;
public:
    CuentaCorriente(string n, string t, double s, double lim, double cargo)
        : Cuenta(n,t,s), limiteCredito(lim), cargoMensual(cargo) {}
    string getTipo() const override { return "Corriente"; }
    double calcularInteres() const override { return 0.0; }
    void retirar(double monto) override {
        if(monto > 0 && monto <= getSaldo() + limiteCredito) setSaldoInterno(getSaldo() - monto);
        else cout << "Retiro rechazado en corriente: supera credito." << endl;
    }
    double getCargoMensual() const { return cargoMensual; }
};

class CuentaInversion : public Cuenta {
private:
    string portafolio[10];
    int numActivos;
    string riesgo;
public:
    CuentaInversion(string n, string t, double s, string r) : Cuenta(n,t,s), numActivos(0), riesgo(r) {}
    string getTipo() const override { return "Inversion"; }
    void agregarActivo(string activo) { if(numActivos < 10) portafolio[numActivos++] = activo; }
    double calcularInteres() const override {
        double tasa = 0.04;
        if(riesgo == "medio") tasa = 0.07;
        if(riesgo == "alto") tasa = 0.12;
        return getSaldo() * tasa;
    }
};

class Banco {
private:
    Cuenta* cuentas[200];
    int numCuentas;
public:
    Banco() : numCuentas(0) { for(int i=0;i<200;i++) cuentas[i]=nullptr; }
    void abrirCuenta(Cuenta* c) { if(c && numCuentas < 200) cuentas[numCuentas++] = c; }
    Cuenta* buscarCuenta(string numCuenta) const {
        for(int i=0;i<numCuentas;i++) if(cuentas[i]->getNumeroCuenta()==numCuenta) return cuentas[i];
        return nullptr;
    }
    void cerrarCuenta(string numCuenta) {
        for(int i=0;i<numCuentas;i++) if(cuentas[i]->getNumeroCuenta()==numCuenta) {
            delete cuentas[i];
            for(int j=i;j<numCuentas-1;j++) cuentas[j]=cuentas[j+1];
            cuentas[numCuentas-1]=nullptr;
            numCuentas--;
            cout << "Cuenta cerrada: " << numCuenta << endl;
            return;
        }
    }
    void aplicarIntereses() { for(int i=0;i<numCuentas;i++) cuentas[i]->depositar(cuentas[i]->calcularInteres()); }
    void imprimirEstadoCuenta(string numCuenta) const { Cuenta* c = buscarCuenta(numCuenta); if(c) c->imprimir(); else cout << "Cuenta no encontrada." << endl; }
    double totalDepositado() const { double t=0; for(int i=0;i<numCuentas;i++) t += cuentas[i]->getSaldo(); return t; }
    void listar() const { for(int i=0;i<numCuentas;i++) cuentas[i]->imprimir(); }
    ~Banco() { for(int i=0;i<numCuentas;i++){ delete cuentas[i]; cuentas[i]=nullptr; } }
};

int main() {
    Banco banco;
    banco.abrirCuenta(new CuentaAhorro("A001", "Ana", 1000, 0.05, 100));
    banco.abrirCuenta(new CuentaCorriente("C001", "Luis", 500, 300, 10));
    CuentaInversion* inv = new CuentaInversion("I001", "Carla", 3000, "alto");
    inv->agregarActivo("ETF");
    inv->agregarActivo("Bonos");
    banco.abrirCuenta(inv);

    banco.listar();
    banco.aplicarIntereses();
    cout << "=== Despues de intereses ===" << endl;
    banco.listar();
    banco.imprimirEstadoCuenta("C001");
    cout << fixed << setprecision(2) << "Total depositado: $" << banco.totalDepositado() << endl;
    banco.cerrarCuenta("C001");
    return 0;
}
