#include <iostream>
using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int dividir(int a, int b) {
    if (b == 0) {
        cout << "Error: division por cero" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    int a, b;
    cin >> a >> b;

    int (*operaciones[4])(int, int) = {sumar, restar, multiplicar, dividir};

    cout << "Suma          : " << operaciones[0](a, b) << endl;
    cout << "Resta         : " << operaciones[1](a, b) << endl;
    cout << "Multiplicacion: " << operaciones[2](a, b) << endl;
    cout << "Division      : " << operaciones[3](a, b) << endl;

    return 0;
}
