#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class Personaje {
private:
    string nombre;
    int vida;
    int ataque;
    int defensa;
    int nivel;

protected:
    void setVida(int v) { vida = v < 0 ? 0 : v; }

public:
    Personaje(string n, int v, int a, int d, int niv) : nombre(n), vida(v), ataque(a), defensa(d), nivel(niv) {}
    string getNombre() const { return nombre; }
    int getVida() const { return vida; }
    int getAtaque() const { return ataque; }
    int getDefensa() const { return defensa; }
    int getNivel() const { return nivel; }
    virtual string getClase() const = 0;
    virtual int habilidadEspecial() = 0;
    void recibirDano(int dano) { setVida(vida - max(0, dano - defensa)); }
    bool estaVivo() const { return vida > 0; }
    virtual void imprimir() const {
        cout << getNombre() << " | " << getClase() << " | Vida: " << vida
             << " | Atq: " << ataque << " | Def: " << defensa << " | Nivel: " << nivel << endl;
    }
    virtual ~Personaje() {}
};

class Guerrero : public Personaje {
public:
    Guerrero(string n, int v, int a, int d, int niv) : Personaje(n,v,a,d,niv) {}
    string getClase() const override { return "Guerrero"; }
    int habilidadEspecial() override { return getAtaque() * 2; }
};

class Mago : public Personaje {
public:
    Mago(string n, int v, int a, int d, int niv) : Personaje(n,v,a,d,niv) {}
    string getClase() const override { return "Mago"; }
    int habilidadEspecial() override { return getAtaque() * 3; }
};

class Arquero : public Personaje {
public:
    Arquero(string n, int v, int a, int d, int niv) : Personaje(n,v,a,d,niv) {}
    string getClase() const override { return "Arquero"; }
    int habilidadEspecial() override { return static_cast<int>(getAtaque() * 1.5); }
};

class Paladin : public Guerrero {
public:
    Paladin(string n, int v, int a, int d, int niv) : Guerrero(n,v,a,d,niv) {}
    string getClase() const override { return "Paladin"; }
    int habilidadEspecial() override {
        setVida(getVida() + 20);
        return getAtaque() * 2;
    }
};

void combate(Personaje& p1, Personaje& p2) {
    cout << "=== Combate: " << p1.getNombre() << " vs " << p2.getNombre() << " ===" << endl;
    int turno = 1;
    while(p1.estaVivo() && p2.estaVivo() && turno <= 10) {
        if(turno % 2 == 1) {
            int dano = p1.habilidadEspecial();
            p2.recibirDano(dano);
            cout << p1.getNombre() << " usa habilidad: " << dano << " de dano." << endl;
        } else {
            int dano = p2.habilidadEspecial();
            p1.recibirDano(dano);
            cout << p2.getNombre() << " usa habilidad: " << dano << " de dano." << endl;
        }
        turno++;
    }
    p1.imprimir();
    p2.imprimir();
}

void torneo(Personaje* participantes[], int n) {
    cout << "=== Torneo ===" << endl;
    for(int i=0;i<n;i++) participantes[i]->imprimir();
    if(n >= 2) combate(*participantes[0], *participantes[1]);
}

int main() {
    Personaje* participantes[4] = {
        new Guerrero("Arthas", 120, 25, 8, 5),
        new Mago("Merlin", 90, 30, 4, 5),
        new Arquero("Legolas", 100, 24, 6, 5),
        new Paladin("Uther", 130, 22, 10, 5)
    };

    torneo(participantes, 4);

    for(int i=0;i<4;i++){ delete participantes[i]; participantes[i]=nullptr; }
    return 0;
}
