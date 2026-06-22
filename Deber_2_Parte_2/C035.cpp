#include <iostream>
#include <string>
using namespace std;

class Volador {
public:
    virtual void volar() { cout << "Volando..." << endl; }
    virtual ~Volador() {}
};

class Nadador {
public:
    virtual void nadar() { cout << "Nadando..." << endl; }
    virtual ~Nadador() {}
};

class Pato : public Volador, public Nadador {
private:
    string nombre;

public:
    Pato(string n) : nombre(n) {}
    void volar() override { cout << nombre << " vuela: Fiu fiu!" << endl; }
    void nadar() override { cout << nombre << " nada: Splash!" << endl; }
};

class Cisne : public Volador, public Nadador {
private:
    string nombre;

public:
    Cisne(string n) : nombre(n) {}
    void volar() override { cout << nombre << " vuela: Aleteo elegante." << endl; }
    void nadar() override { cout << nombre << " nada: Deslizamiento suave." << endl; }
};

int main() {
    Pato pato("Donald");
    Cisne cisne("Odette");

    pato.volar();
    pato.nadar();
    cisne.volar();
    cisne.nadar();

    return 0;
}
