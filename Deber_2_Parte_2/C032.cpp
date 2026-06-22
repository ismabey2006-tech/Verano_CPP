#include <iostream>
using namespace std;

int main() {
    cout << "C032 - protected vs private" << endl;
    cout << "Linea A: SI compila. area es protected y la clase hija puede acceder." << endl;
    cout << "Linea B: NO compila. tipo es private en Figura; la hija no puede nombrarlo directamente." << endl;
    cout << "Linea C: SI compila. getTipo() es public y area es protected accesible dentro de la hija." << endl;
    cout << "Linea D: NO compila. tipo sigue siendo private; solo Figura puede acceder directamente." << endl;
    cout << "Linea E: NO compila. area es protected; desde main no se puede acceder." << endl;
    cout << "Linea F: SI compila. getTipo() es public." << endl;
    return 0;
}
