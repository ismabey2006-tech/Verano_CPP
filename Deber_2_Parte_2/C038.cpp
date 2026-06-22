#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nombre;

public:
    Animal(string n) : nombre(n) {}
    virtual void hacerSonido() const { cout << "..."; }
    virtual void imprimir() const {
        cout << nombre << " : ";
        hacerSonido();
        cout << endl;
    }
    virtual ~Animal() {}
};

class Perro : public Animal {
public:
    Perro(string n) : Animal(n) {}
    void hacerSonido() const override { cout << "Guau!"; }
};

class Gato : public Animal {
public:
    Gato(string n) : Animal(n) {}
    void hacerSonido() const override { cout << "Miau!"; }
};

class Pajaro : public Animal {
private:
    bool habla;

public:
    Pajaro(string n, bool h=false) : Animal(n), habla(h) {}
    void hacerSonido() const override {
        if (habla) cout << "Loro quiere galleta!";
        else cout << "Pio pio!";
    }
};

int main() {
    Animal* animales[6] = {
        new Perro("Rex"), new Gato("Luna"), new Pajaro("Pio"),
        new Perro("Max"), new Gato("Pelusa"), new Pajaro("Loro", true)
    };

    for (int i = 0; i < 6; i++) {
        animales[i]->imprimir();
    }

    for (int i = 0; i < 6; i++) {
        delete animales[i];
        animales[i] = nullptr;
    }

    return 0;
}
