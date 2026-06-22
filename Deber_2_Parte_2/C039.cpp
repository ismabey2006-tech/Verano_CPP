#include <iostream>
using namespace std;

int main() {
    cout << "C039 - Analisis: cuando usar herencia" << endl;
    cout << "a) SI. Auto y Camion pueden heredar de Vehiculo porque ambos SON vehiculos y comparten comportamiento esencial." << endl;
    cout << "b) NO. Que Perro y Mesa tengan peso no basta; no existe una relacion natural de tipo 'es un'." << endl;
    cout << "c) SI. Circulo y Cuadrado pueden heredar de Figura porque ambos son figuras con area y perimetro." << endl;
    cout << "d) SI, si Manager realmente es un tipo de Empleado con datos adicionales. Si solo coordina empleados, seria composicion." << endl;
    return 0;
}
