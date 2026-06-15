#include <iostream>
using namespace std;

/*
RESPUESTA C008 — ANÁLISIS

a) areaCirculo(5.0) usa una función libre: el radio se pasa como dato suelto.
   En cambio, c.area() trabaja sobre el objeto c, que ya contiene su propio radio.

b) Si hay 100 círculos, la versión con clase es más ordenada, porque cada objeto
   guarda su radio y sus métodos. No hay que pasar el radio a cada función.

c) En la versión A, si 10 funciones necesitan el radio, se debe enviar el mismo
   dato a todas. Eso aumenta repetición y facilita errores. Con clase, el dato
   queda dentro del objeto.
*/

double areaCirculo(double r) { return 3.14159 * r * r; }
double periCirculo(double r) { return 2 * 3.14159 * r; }

class Circulo {
public:
    double radio;
    double area()      { return 3.14159 * radio * radio; }
    double perimetro() { return 2 * 3.14159 * radio; }
};

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "Funcion libre areaCirculo(5.0): " << areaCirculo(5.0) << endl;

    Circulo c;
    c.radio = 5.0;
    cout << "Metodo de objeto c.area(): " << c.area() << endl;

    return 0;
}
