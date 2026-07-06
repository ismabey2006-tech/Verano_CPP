#include <iostream>
using namespace std;

/*
P003 | Reescribir un switch con polimorfismo

En la version sin polimorfismo, para agregar Pato habria que modificar
emitirSonido() y agregar otro else if.

En esta version con polimorfismo, solo se agrega la clase Pato. El codigo
que recorre el arreglo no cambia, porque trabaja mediante la interfaz Animal.
Pato puede existir sin tocar main porque cada clase sabe como hacer su propio
sonido mediante hacerSonido().
*/

class Animal {
public:
    virtual void hacerSonido() const = 0;
    virtual ~Animal() {}
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        cout << "Guau!" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        cout << "Miau!" << endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido() const override {
        cout << "Muuu!" << endl;
    }
};

class Pato : public Animal {
public:
    void hacerSonido() const override {
        cout << "Cuac!" << endl;
    }
};

int main() {
    Animal* animales[4];
    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Vaca();
    animales[3] = new Perro();

    for (int i = 0; i < 4; ++i) {
        animales[i]->hacerSonido();
    }

    for (int i = 0; i < 4; ++i) {
        delete animales[i];
        animales[i] = nullptr;
    }

    return 0;
}
