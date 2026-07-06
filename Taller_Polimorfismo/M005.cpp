#include <iostream>
using namespace std;

/*
M005 | ANALISIS — detectar leaks en jerarquia

Problema A — donde:
  En Figura::~Figura(), porque el destructor no es virtual.

Que ocurre:
  Si se hace delete usando Figura* que apunta a FiguraColor, solo se llama
  ~Figura(). Entonces la memoria de paleta, propia de FiguraColor, puede no
  liberarse correctamente.

Correccion:
  virtual ~Figura() { delete[] coords; coords = nullptr; }

Problema B — donde:
  En Canvas::~Canvas(), porque solo hace delete[] figuras.

Que ocurre:
  Se libera el arreglo de punteros, pero no los objetos FiguraColor creados
  con new que estan dentro del arreglo.

Correccion:
  Recorrer desde 0 hasta cantidad - 1, hacer delete figuras[i], luego
  delete[] figuras.

Problema C — donde:
  En main:
    Figura* f = new FiguraColor(2, 2);
    f = new FiguraColor(8, 4);

Que ocurre:
  Se pierde la direccion del primer objeto y ya no se puede liberar. Eso es
  un memory leak.

Correccion:
  Hacer delete f antes de reasignarlo, o no reasignar el mismo puntero.
*/

class Figura {
protected:
    double* coords;

public:
    Figura(int n) {
        coords = new double[n];
    }

    virtual ~Figura() {
        delete[] coords;
        coords = nullptr;
    }
};

class FiguraColor : public Figura {
private:
    int* paleta;

public:
    FiguraColor(int n, int c) : Figura(n) {
        paleta = new int[c];
    }

    ~FiguraColor() override {
        delete[] paleta;
        paleta = nullptr;
    }
};

class Canvas {
private:
    Figura** figuras;
    int cantidad;
    int capacidad;

public:
    Canvas(int capacidad = 10) : cantidad(0), capacidad(capacidad) {
        figuras = new Figura*[capacidad];
    }

    void agregar(Figura* f) {
        if (cantidad < capacidad) {
            figuras[cantidad++] = f;
        } else {
            cout << "Canvas lleno. Se libera la figura no agregada." << endl;
            delete f;
        }
    }

    ~Canvas() {
        for (int i = 0; i < cantidad; ++i) {
            delete figuras[i];
            figuras[i] = nullptr;
        }
        delete[] figuras;
        figuras = nullptr;
    }
};

int main() {
    Canvas c;
    c.agregar(new FiguraColor(4, 3));
    c.agregar(new FiguraColor(6, 5));

    Figura* f = new FiguraColor(2, 2);
    delete f;
    f = nullptr;

    f = new FiguraColor(8, 4);
    delete f;
    f = nullptr;

    cout << "Correcciones aplicadas: sin leaks intencionales." << endl;
    return 0;
}
