#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14159;

double areaRectangulo(double base, double altura){
    return base * altura;
}

double areaTriangulo(double base, double altura){
    return base * altura / 2.0;
}

double areaCirculo(double radio){
    return PI * radio * radio;
}

void mostrarMenu(){
    cout << "=== Calculadora de areas ===" << endl;
    cout << "1. Rectangulo" << endl;
    cout << "2. Triangulo" << endl;
    cout << "3. Circulo" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
}

int main(){
    int opcion;
    double base, altura, radio;

    cout << fixed << setprecision(2);

    do{
        mostrarMenu();
        cin >> opcion;

        if(opcion == 1){
            cin >> base >> altura;
            cout << "Base: " << base << "  Altura: " << altura << " -> Area: " << areaRectangulo(base, altura) << endl;
        }
        else if(opcion == 2){
            cin >> base >> altura;
            cout << "Base: " << base << "  Altura: " << altura << " -> Area: " << areaTriangulo(base, altura) << endl;
        }
        else if(opcion == 3){
            cin >> radio;
            cout << "Radio: " << radio << " -> Area: " << areaCirculo(radio) << endl;
        }
        else if(opcion == 4){
            cout << "Hasta pronto." << endl;
        }
    }while(opcion != 4);

    return 0;
}
