#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Mascota {
protected:
    string nombre;
    double precio;

public:
    Mascota(string nombre, double precio) : nombre(nombre), precio(precio) {}

    virtual string tipo() const = 0;
    virtual string sonido() const = 0;

    virtual void describir() const {
        cout << "[" << tipo() << "] " << nombre << " - $"
             << fixed << setprecision(2) << precio << " - " << sonido() << endl;
    }

    virtual ~Mascota() {}
};

class Perro : public Mascota {
private:
    string raza;

public:
    Perro(string nombre, string raza, double precio)
        : Mascota(nombre, precio), raza(raza) {}

    string tipo() const override { return "Perro"; }
    string sonido() const override { return "Guau!"; }

    void describir() const override {
        cout << "[Perro] " << nombre << " (" << raza << ") - $"
             << fixed << setprecision(2) << precio << " - " << sonido() << endl;
    }
};

class Gato : public Mascota {
private:
    string colorOjos;

public:
    Gato(string nombre, string colorOjos, double precio)
        : Mascota(nombre, precio), colorOjos(colorOjos) {}

    string tipo() const override { return "Gato"; }
    string sonido() const override { return "Miau!"; }

    void describir() const override {
        cout << "[Gato] " << nombre << " (ojos " << colorOjos << ") - $"
             << fixed << setprecision(2) << precio << " - " << sonido() << endl;
    }
};

class Conejo : public Mascota {
private:
    double pesoKg;

public:
    Conejo(string nombre, double pesoKg, double precio)
        : Mascota(nombre, precio), pesoKg(pesoKg) {}

    string tipo() const override { return "Conejo"; }
    string sonido() const override { return "..."; }

    void describir() const override {
        cout << "[Conejo] " << nombre << " (" << pesoKg << " kg) - $"
             << fixed << setprecision(2) << precio << " - " << sonido() << endl;
    }
};

void agregarMascota(Mascota** mascotas, int& cantidad, int capacidad) {
    if (cantidad >= capacidad) {
        cout << "Capacidad llena. No se pueden agregar mas mascotas." << endl;
        return;
    }

    string tipo;
    string nombre;
    double precio;

    cout << "Tipo (perro/gato/conejo): ";
    cin >> tipo;

    cout << "Nombre: ";
    cin >> nombre;

    if (tipo == "perro") {
        string raza;
        cout << "Raza: ";
        cin >> raza;
        cout << "Precio: ";
        cin >> precio;
        mascotas[cantidad++] = new Perro(nombre, raza, precio);
    } else if (tipo == "gato") {
        string colorOjos;
        cout << "Color de ojos: ";
        cin >> colorOjos;
        cout << "Precio: ";
        cin >> precio;
        mascotas[cantidad++] = new Gato(nombre, colorOjos, precio);
    } else if (tipo == "conejo") {
        double pesoKg;
        cout << "Peso kg: ";
        cin >> pesoKg;
        cout << "Precio: ";
        cin >> precio;
        mascotas[cantidad++] = new Conejo(nombre, pesoKg, precio);
    } else {
        cout << "Tipo no reconocido." << endl;
    }
}

void listarMascotas(Mascota** mascotas, int cantidad) {
    if (cantidad == 0) {
        cout << "No hay mascotas registradas." << endl;
        return;
    }

    for (int i = 0; i < cantidad; ++i) {
        mascotas[i]->describir();
    }
}

void buscarPorTipo(Mascota** mascotas, int cantidad) {
    string busqueda;
    bool encontrado = false;

    cout << "Buscar tipo: ";
    cin >> busqueda;

    for (int i = 0; i < cantidad; ++i) {
        if (busqueda == "perro") {
            Perro* p = dynamic_cast<Perro*>(mascotas[i]);
            if (p != nullptr) {
                p->describir();
                encontrado = true;
            }
        } else if (busqueda == "gato") {
            Gato* g = dynamic_cast<Gato*>(mascotas[i]);
            if (g != nullptr) {
                g->describir();
                encontrado = true;
            }
        } else if (busqueda == "conejo") {
            Conejo* c = dynamic_cast<Conejo*>(mascotas[i]);
            if (c != nullptr) {
                c->describir();
                encontrado = true;
            }
        } else {
            cout << "Tipo no reconocido." << endl;
            return;
        }
    }

    if (!encontrado) {
        cout << "No hay mascotas de ese tipo." << endl;
    }
}

int main() {
    const int capacidad = 10;
    Mascota** mascotas = new Mascota*[capacidad];
    int cantidad = 0;
    int opcion = 0;

    do {
        cout << "\n=== TIENDA DE MASCOTAS ===" << endl;
        cout << "1. Agregar  2. Listar  3. Buscar  4. Salir" << endl;
        cout << "> ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarMascota(mascotas, cantidad, capacidad);
                break;
            case 2:
                listarMascotas(mascotas, cantidad);
                break;
            case 3:
                buscarPorTipo(mascotas, cantidad);
                break;
            case 4:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 4);

    for (int i = 0; i < cantidad; ++i) {
        delete mascotas[i];
        mascotas[i] = nullptr;
    }
    delete[] mascotas;
    mascotas = nullptr;

    cout << "Hasta luego. Memoria liberada." << endl;
    return 0;
}
