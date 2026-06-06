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

    virtual ~Animal(){}

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
    Animal* animales[4];

    animales[0] = new Perro("Rex");
    animales[1] = new Gato("Luna");
    animales[2] = new Perro("Max");
    animales[3] = new Gato("Michi");

    for(int i = 0; i < 4; i++){
        cout << animales[i]->getNombre() << ": ";
        animales[i]->hacerSonido();
        cout << endl;
    }

    for(int i = 0; i < 4; i++){
        delete animales[i];
        animales[i] = nullptr;
    }

    return 0;
}
