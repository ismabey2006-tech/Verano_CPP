#include <iostream>
#include <iomanip>
using namespace std;

class CuentaBancaria{
private:
    double saldo;

public:
    CuentaBancaria(double saldoInicial){
        saldo = saldoInicial;
    }

    bool depositar(double monto){
        if(monto > 0){
            saldo += monto;
            return true;
        }
        return false;
    }

    bool retirar(double monto){
        if(monto > 0 && monto <= saldo){
            saldo -= monto;
            return true;
        }
        return false;
    }

    double getSaldo(){
        return saldo;
    }
};

void mostrarMenu(){
    cout << "=== Menu ===" << endl;
    cout << "1. Depositar  2. Retirar  3. Ver saldo  4. Salir" << endl;
    cout << "Opcion: ";
}

int main(){
    double saldoInicial, monto;
    int opcion;

    cin >> saldoInicial;

    CuentaBancaria cuenta(saldoInicial);

    cout << fixed << setprecision(2);
    cout << "Saldo inicial: $" << cuenta.getSaldo() << endl;

    do{
        mostrarMenu();
        cin >> opcion;

        if(opcion == 1){
            cin >> monto;
            cout << "Monto: ";
            if(cuenta.depositar(monto)){
                cout << "Deposito OK. Saldo: $" << cuenta.getSaldo() << endl;
            }
            else{
                cout << "Error: monto invalido. Saldo: $" << cuenta.getSaldo() << endl;
            }
        }
        else if(opcion == 2){
            cin >> monto;
            cout << "Monto: ";
            if(cuenta.retirar(monto)){
                cout << "Retiro OK. Saldo: $" << cuenta.getSaldo() << endl;
            }
            else{
                cout << "Error: saldo insuficiente. Saldo: $" << cuenta.getSaldo() << endl;
            }
        }
        else if(opcion == 3){
            cout << "Saldo: $" << cuenta.getSaldo() << endl;
        }
        else if(opcion == 4){
            cout << "Hasta pronto." << endl;
        }
    }while(opcion != 4);

    return 0;
}
