#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Instrumento {
protected:
    string nombre;
    double precio;
public:
    Instrumento(string n, double p) : nombre(n), precio(p >= 0 ? p : 0) {}
    virtual void tocar() const = 0;
    virtual string getFamilia() const = 0;
    virtual double getPrecio() const { return precio; }
    virtual void imprimir() const {
        cout << fixed << setprecision(2);
        cout << nombre << " | Familia: " << getFamilia() << " | Precio: $" << getPrecio() << endl;
    }
    virtual ~Instrumento() {}
};

class Cuerdas : public Instrumento {
public:
    Cuerdas(string n, double p) : Instrumento(n,p) {}
    string getFamilia() const override { return "Cuerdas"; }
    virtual int getCuerdas() const = 0;
};

class Viento : public Instrumento {
public:
    Viento(string n, double p) : Instrumento(n,p) {}
    string getFamilia() const override { return "Viento"; }
    virtual string getMaterial() const = 0;
};

class Percusion : public Instrumento {
public:
    Percusion(string n, double p) : Instrumento(n,p) {}
    string getFamilia() const override { return "Percusion"; }
};

class Guitarra : public Cuerdas {
public:
    Guitarra(string n, double p) : Cuerdas(n,p) {}
    void tocar() const override { cout << nombre << ": rasgueo de guitarra." << endl; }
    int getCuerdas() const override { return 6; }
};
class Violin : public Cuerdas {
public:
    Violin(string n, double p) : Cuerdas(n,p) {}
    void tocar() const override { cout << nombre << ": melodia de violin." << endl; }
    int getCuerdas() const override { return 4; }
};
class Trompeta : public Viento {
public:
    Trompeta(string n, double p) : Viento(n,p) {}
    void tocar() const override { cout << nombre << ": sonido brillante de trompeta." << endl; }
    string getMaterial() const override { return "Metal"; }
};
class Flauta : public Viento {
public:
    Flauta(string n, double p) : Viento(n,p) {}
    void tocar() const override { cout << nombre << ": sonido suave de flauta." << endl; }
    string getMaterial() const override { return "Madera"; }
};
class Bateria : public Percusion {
public:
    Bateria(string n, double p) : Percusion(n,p) {}
    void tocar() const override { cout << nombre << ": ritmo de bateria." << endl; }
};
class Tambor : public Percusion {
public:
    Tambor(string n, double p) : Percusion(n,p) {}
    void tocar() const override { cout << nombre << ": golpe de tambor." << endl; }
};

int main() {
    Instrumento* orquesta[8] = {
        new Guitarra("Guitarra clasica", 500), new Violin("Violin principal", 900),
        new Trompeta("Trompeta jazz", 650), new Flauta("Flauta dulce", 120),
        new Bateria("Bateria completa", 1500), new Tambor("Tambor andino", 180),
        new Guitarra("Guitarra electrica", 800), new Tambor("Tambor ceremonial", 220)
    };

    int cuerdas=0, viento=0, percusion=0;
    double total = 0;
    cout << "=== Tocando ===" << endl;
    for(int i=0;i<8;i++) {
        orquesta[i]->tocar();
        if(orquesta[i]->getFamilia()=="Cuerdas") cuerdas++;
        else if(orquesta[i]->getFamilia()=="Viento") viento++;
        else if(orquesta[i]->getFamilia()=="Percusion") percusion++;
        total += orquesta[i]->getPrecio();
    }

    cout << "=== Agrupacion ===" << endl;
    cout << "Cuerdas: " << cuerdas << endl;
    cout << "Viento: " << viento << endl;
    cout << "Percusion: " << percusion << endl;
    cout << fixed << setprecision(2) << "Valor total: $" << total << endl;

    for(int i=0;i<8;i++){ delete orquesta[i]; orquesta[i]=nullptr; }
    return 0;
}
