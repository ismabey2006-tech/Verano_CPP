#include <iostream>
using namespace std;

/*
RESPUESTA C022 — TRAZA const
Linea A: NO compila. getDoble() es const y no puede modificar contenido.
Linea B: si A se comenta, SI compila porque solo retorna contenido.
Linea C: SI compila. c no es const y getContenido() es const.
Linea D: SI compila. c no es const y puede llamar setter.
Linea E: SI compila. fija es const y puede llamar metodos const.
Linea F: NO compila. fija es const y setContenido() modifica el objeto.
*/

class Caja {
private:
    int contenido;

public:
    Caja(int c) : contenido(c) {}

    int getContenido() const { return contenido; }
    void setContenido(int c) { contenido = c; }

    int getDoble() const {
        // contenido = contenido * 2; // Linea A: error si se descomenta.
        return contenido * 2;
    }
};

int main() {
    Caja c(10);
    const Caja fija(99);

    cout << "Linea C: " << c.getContenido() << endl;
    c.setContenido(20);
    cout << "Linea D despues de set: " << c.getContenido() << endl;
    cout << "Linea E: " << fija.getContenido() << endl;
    // fija.setContenido(50); // Linea F: error si se descomenta.
    cout << "Doble de c: " << c.getDoble() << endl;

    return 0;
}
