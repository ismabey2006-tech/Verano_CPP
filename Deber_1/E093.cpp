#include <iostream>
#include <string>
using namespace std;

class Animal{
protected:
    string nombre;

public:
    Animal(string n){
        nombre = n;
    }

    virtual void hacerSonido(){
        cout << "...";
    }

    string getNombre(){
        return nombre;
    }
};

class Perro : public Animal{
public:
    Perro(string n) : Animal(n){}

    void hacerSonido(){
        cout << "Guau!";
    }
};

class Gato : public Animal{
public:
    Gato(string n) : Animal(n){}

    void hacerSonido(){
        cout << "Miau!";
    }
};

int main(){
    Perro perro("Rex");
    Gato gato("Luna");

    cout << "Perro (" << perro.getNombre() << "): ";
    perro.hacerSonido();
    cout << endl;

    cout << "Gato (" << gato.getNombre() << "): ";
    gato.hacerSonido();
    cout << endl;

    return 0;
}
