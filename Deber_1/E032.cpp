#include <iostream>
#include <iomanip>
using namespace std;

double celsiusAFahrenheit(double c){
    return (c * 9.0 / 5.0) + 32.0;
}

double fahrenheitACelsius(double f){
    return (f - 32.0) * 5.0 / 9.0;
}

void mostrarConversion(double valor, char tipo){
    cout << fixed << setprecision(1);

    if(tipo == 'C'){
        double resultado = celsiusAFahrenheit(valor);
        cout << valor << " C equivale a " << resultado << " F" << endl;
    }
    else if(tipo == 'F'){
        double resultado = fahrenheitACelsius(valor);
        cout << valor << " F equivale a " << resultado << " C" << endl;
    }
    else{
        cout << "Tipo invalido" << endl;
    }
}

int main(){
    double valor;
    char tipo;

    cin >> valor;
    cin >> tipo;

    mostrarConversion(valor, tipo);

    return 0;
}
