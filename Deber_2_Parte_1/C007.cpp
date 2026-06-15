#include <iostream>
using namespace std;

class Temperatura {
public:
    double celsius;

    double getCelsius();
    double getFahrenheit();
    double getKelvin();
    void imprimir();
};

double Temperatura::getCelsius() {
    return celsius;
}

double Temperatura::getFahrenheit() {
    return celsius * 9.0 / 5.0 + 32.0;
}

double Temperatura::getKelvin() {
    return celsius + 273.15;
}

void Temperatura::imprimir() {
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Celsius   : " << getCelsius() << endl;
    cout << "Fahrenheit: " << getFahrenheit() << endl;
    cout << "Kelvin    : " << getKelvin() << endl;
}

int main() {
    Temperatura t;
    t.celsius = 100.0;
    t.imprimir();
    return 0;
}
