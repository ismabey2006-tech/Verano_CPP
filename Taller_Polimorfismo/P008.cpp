#include <iostream>
using namespace std;

/*
P008 | ANALISIS — Errores comunes con mensajes de compilador

Fragmento A:
- No compila.
- Error en compilacion.
- Animal es abstracta porque tiene virtual void hablar() = 0.
- Correccion: no instanciar Animal directamente; crear una clase derivada
  concreta que implemente hablar().

Fragmento B:
- No compila.
- Error en compilacion.
- void habla() override no sobrescribe Animal::hablar(); hay un typo.
- Correccion: cambiar habla() por hablar().

Fragmento C:
- Compila, pero el problema aparece en ejecucion al hacer delete por Animal*.
- Como ~Animal no es virtual, no se llama ~Perro(). Si Perro tiene memoria
  dinamica propia, esa memoria queda sin liberar.
- Correccion: hacer virtual el destructor de Animal.

Fragmento D:
- No compila.
- Error en compilacion.
- Circulo sigue siendo abstracta porque no implementa area().
- Correccion: implementar double area() override.
*/

namespace CorreccionA {
    class Animal {
    public:
        virtual void hablar() = 0;
        virtual ~Animal() {}
    };

    class Perro : public Animal {
    public:
        void hablar() override {
            cout << "Guau" << endl;
        }
    };

    void demo() {
        Animal* a = new Perro();
        a->hablar();
        delete a;
    }
}

namespace CorreccionB {
    class Animal {
    public:
        virtual void hablar() { cout << "..." << endl; }
        virtual ~Animal() {}
    };

    class Perro : public Animal {
    public:
        void hablar() override {
            cout << "Guau" << endl;
        }
    };

    void demo() {
        Perro p;
        p.hablar();
    }
}

namespace CorreccionC {
    class Animal {
    public:
        virtual void hablar() { cout << "Animal" << endl; }
        virtual ~Animal() {}
    };

    class Perro : public Animal {
    private:
        int* datos;

    public:
        Perro() {
            datos = new int[100];
        }

        ~Perro() override {
            delete[] datos;
            datos = nullptr;
            cout << "~Perro: memoria liberada" << endl;
        }
    };

    void demo() {
        Animal* a = new Perro();
        delete a;
    }
}

namespace CorreccionD {
    class Figura {
    public:
        virtual double area() const = 0;
        virtual ~Figura() {}
    };

    class Circulo : public Figura {
    private:
        double radio;

    public:
        Circulo(double r) : radio(r) {}

        double area() const override {
            return 3.14159265358979323846 * radio * radio;
        }
    };

    void demo() {
        Circulo c(5.0);
        cout << c.area() << endl;
    }
}

int main() {
    cout << "Correccion A: ";
    CorreccionA::demo();

    cout << "Correccion B: ";
    CorreccionB::demo();

    cout << "Correccion C: ";
    CorreccionC::demo();

    cout << "Correccion D: ";
    CorreccionD::demo();

    return 0;
}
