#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
P012 | Diseñar una interfaz desde un enunciado

Ventaja de MedioPago como interfaz:
Si mañana se agrega Criptomoneda, se crea una nueva clase que hereda de
MedioPago e implementa el contrato. El codigo que procesa un arreglo de
MedioPago* puede seguir igual.
*/

class MedioPago {
public:
    virtual void procesar(double monto) = 0;
    virtual bool fueExitoso() const = 0;
    virtual void imprimirComprobante(double monto) const = 0;
    virtual ~MedioPago() {}
};

class TarjetaCredito : public MedioPago {
private:
    string ultimos4;
    bool aprobado;

public:
    TarjetaCredito(string ultimos4) : ultimos4(ultimos4), aprobado(false) {}

    void procesar(double monto) override {
        aprobado = monto > 0.0;
        cout << "[Tarjeta] Procesando $" << fixed << setprecision(2) << monto
             << "... " << (aprobado ? "Aprobado." : "Rechazado.") << endl;
    }

    bool fueExitoso() const override {
        return aprobado;
    }

    void imprimirComprobante(double monto) const override {
        if (aprobado) {
            cout << "Comprobante: TC-****" << ultimos4 << " $"
                 << fixed << setprecision(2) << monto << endl;
        }
    }
};

class TransferenciaBancaria : public MedioPago {
private:
    string codigo;
    bool aprobado;

public:
    TransferenciaBancaria(string codigo) : codigo(codigo), aprobado(false) {}

    void procesar(double monto) override {
        aprobado = monto > 0.0;
        cout << "[Transferencia] Procesando $" << fixed << setprecision(2) << monto
             << "... " << (aprobado ? "Aprobado." : "Rechazado.") << endl;
    }

    bool fueExitoso() const override {
        return aprobado;
    }

    void imprimirComprobante(double monto) const override {
        if (aprobado) {
            cout << "Comprobante: " << codigo << " $"
                 << fixed << setprecision(2) << monto << endl;
        }
    }
};

class Efectivo : public MedioPago {
private:
    string codigo;
    bool aprobado;

public:
    Efectivo(string codigo) : codigo(codigo), aprobado(false) {}

    void procesar(double monto) override {
        aprobado = monto > 0.0;
        cout << "[Efectivo] Procesando $" << fixed << setprecision(2) << monto
             << "... " << (aprobado ? "Aprobado." : "Rechazado.") << endl;
    }

    bool fueExitoso() const override {
        return aprobado;
    }

    void imprimirComprobante(double monto) const override {
        if (aprobado) {
            cout << "Comprobante: " << codigo << " $"
                 << fixed << setprecision(2) << monto << endl;
        }
    }
};

int main() {
    MedioPago* pagos[3];
    double montos[3] = {150.0, 500.0, 20.0};

    pagos[0] = new TarjetaCredito("1234");
    pagos[1] = new TransferenciaBancaria("TR-001");
    pagos[2] = new Efectivo("EF-001");

    for (int i = 0; i < 3; ++i) {
        pagos[i]->procesar(montos[i]);
        if (pagos[i]->fueExitoso()) {
            pagos[i]->imprimirComprobante(montos[i]);
        }
    }

    for (int i = 0; i < 3; ++i) {
        delete pagos[i];
        pagos[i] = nullptr;
    }

    return 0;
}
