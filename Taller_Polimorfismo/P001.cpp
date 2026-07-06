#include <iostream>
#include <string>
using namespace std;

/*
P001 | Reconocer polimorfismo estatico

Respuestas:
a) Salida exacta antes de agregar imprimir(bool):
   Entero: 42
   Double: 3.14
   Texto: hola
   Suma: 7

b) Existen 4 versiones originales de imprimir():
   imprimir(int), imprimir(double), imprimir(string), imprimir(int, int).
   Las diferencia su firma: cantidad y tipo de parametros.

c) El compilador decide cual version llamar en tiempo de compilacion.
   Por eso es polimorfismo estatico o binding estatico.

d) Quinta version agregada abajo: imprimir(bool b).
   Con imprimir(bool), una llamada como imp.imprimir("hola") podria ser
   problematica porque "hola" es const char*, no string. C++ podria convertir
   un puntero a bool, o tambien construir un string si existe una sobrecarga
   compatible; para evitar sorpresas se usa string("hola") explicitamente.
*/

class Impresora {
public:
    void imprimir(int n) {
        cout << "Entero: " << n << endl;
    }

    void imprimir(double d) {
        cout << "Double: " << d << endl;
    }

    void imprimir(string s) {
        cout << "Texto: " << s << endl;
    }

    void imprimir(int a, int b) {
        cout << "Suma: " << a + b << endl;
    }

    void imprimir(bool b) {
        cout << (b ? "Verdadero" : "Falso") << endl;
    }
};

int main() {
    Impresora imp;

    imp.imprimir(42);
    imp.imprimir(3.14);
    imp.imprimir(string("hola"));
    imp.imprimir(3, 4);
    imp.imprimir(true);

    return 0;
}
