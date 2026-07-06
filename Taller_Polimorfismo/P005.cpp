#include <iostream>
#include <string>
using namespace std;

/*
P005 | TRAZA — Slicing, el error silencioso

a) Salida:
   Linea 1: Figura
   Linea 2: Rectangulo
   Linea 3: Rectangulo

b) El slicing ocurre en la linea 1, porque Rectangulo r se copia por valor
   dentro de un parametro Figura f. La parte derivada Rectangulo se pierde.

c) Linea 2 usa puntero; linea 3 usa referencia. Ambas evitan slicing.
   Preferiria referencia cuando el argumento no puede ser null y no necesito
   reasignarlo. Usaria puntero cuando null tiene sentido o quiero indicar
   que podria no existir objeto.

d) Para evitar slicing, cambiar la firma a:
   void porValor(const Figura& f)
   En realidad ya no seria "por valor", sino por referencia constante.
*/

class Figura {
public:
    virtual string nombre() const { return "Figura"; }

    void describir() const {
        cout << nombre() << endl;
    }

    virtual ~Figura() {}
};

class Rectangulo : public Figura {
public:
    string nombre() const override { return "Rectangulo"; }
};

void porValor(Figura f) {
    f.describir();
}

void porPuntero(Figura* f) {
    if (f != nullptr) {
        f->describir();
    }
}

void porReferencia(Figura& f) {
    f.describir();
}

// Version corregida para evitar slicing:
void sinSlicing(const Figura& f) {
    f.describir();
}

int main() {
    Rectangulo r;

    cout << "porValor: ";
    porValor(r);

    cout << "porPuntero: ";
    porPuntero(&r);

    cout << "porReferencia: ";
    porReferencia(r);

    cout << "sinSlicing: ";
    sinSlicing(r);

    return 0;
}
