#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double calcularPromedio3(double a, double b, double c){
    return (a + b + c) / 3.0;
}

double calcularAreaRectangulo(double base, double altura){
    return base * altura;
}

bool esMayorDeEdad(int edad){
    return edad >= 18;
}

string clasificarEdad(int edad){
    if(edad < 12){
        return "Niño";
    }
    if(edad <= 17){
        return "Adolescente";
    }
    return "Adulto";
}

int main(){
    double n1, n2, n3, base, altura;
    int edad;

    cin >> n1 >> n2 >> n3;
    cin >> base >> altura;
    cin >> edad;

    cout << fixed << setprecision(2);
    cout << "Promedio de notas: " << calcularPromedio3(n1, n2, n3) << endl;
    cout << "Area del rectangulo: " << calcularAreaRectangulo(base, altura) << endl;
    cout << "Edad " << edad << ": " << clasificarEdad(edad);

    if(esMayorDeEdad(edad)){
        cout << " (mayor de edad)" << endl;
    }
    else{
        cout << " (menor de edad)" << endl;
    }

    return 0;
}
