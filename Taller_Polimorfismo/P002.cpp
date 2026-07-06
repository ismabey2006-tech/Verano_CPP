#include <iostream>
using namespace std;

/*
P002 | TRAZA DOBLE — con y sin virtual

SIN virtual, la salida es:
  Forma::dibujar
  Circulo::dibujar
  Forma::dibujar
  Forma::dibujar

CON virtual en Forma::dibujar(), la salida es:
  Forma::dibujar
  Circulo::dibujar
  Forma::dibujar
  Circulo::dibujar

Llamadas afectadas:
- fo.dibujar(): no cambia, el objeto real es Forma.
- ci.dibujar(): no cambia, el objeto se conoce directamente como Circulo.
- probar(&fo): no cambia, el objeto real es Forma.
- probar(&ci): si cambia, porque Forma* apunta a un Circulo real.

Sin virtual hay binding estatico: se usa el tipo declarado del puntero.
Con virtual hay binding dinamico: se usa el tipo real del objeto en ejecucion.
*/

class FormaNoVirtual {
public:
    void dibujar() {
        cout << "Forma::dibujar" << endl;
    }
};

class CirculoNoVirtual : public FormaNoVirtual {
public:
    void dibujar() {
        cout << "Circulo::dibujar" << endl;
    }
};

void probar(FormaNoVirtual* f) {
    f->dibujar();
}

class FormaVirtual {
public:
    virtual void dibujar() {
        cout << "Forma::dibujar" << endl;
    }

    virtual ~FormaVirtual() {}
};

class CirculoVirtual : public FormaVirtual {
public:
    void dibujar() override {
        cout << "Circulo::dibujar" << endl;
    }
};

void probar(FormaVirtual* f) {
    f->dibujar();
}

int main() {
    cout << "--- SIN virtual ---" << endl;
    FormaNoVirtual fo;
    CirculoNoVirtual ci;

    fo.dibujar();
    ci.dibujar();
    probar(&fo);
    probar(&ci);

    cout << "\n--- CON virtual ---" << endl;
    FormaVirtual fv;
    CirculoVirtual cv;

    fv.dibujar();
    cv.dibujar();
    probar(&fv);
    probar(&cv);

    return 0;
}
