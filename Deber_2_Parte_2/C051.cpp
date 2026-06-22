#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Material {
private:
    string codigo;
    string titulo;
    int anio;

public:
    Material(string c, string t, int a) : codigo(c), titulo(t), anio(a) {}
    string getCodigo() const { return codigo; }
    string getTitulo() const { return titulo; }
    int getAnio() const { return anio; }
    virtual string getTipo() const = 0;
    virtual bool esPrestable() const = 0;
    virtual void imprimir() const {
        cout << getTipo() << " [" << codigo << "] " << titulo << " (" << anio << ")"
             << " | Prestable: " << (esPrestable() ? "SI" : "NO");
    }
    virtual ~Material() {}
};

class Libro : public Material {
private:
    string autor;
    int paginas;

public:
    Libro(string c, string t, int a, string au, int p) : Material(c, t, a), autor(au), paginas(p) {}
    string getTipo() const override { return "Libro"; }
    bool esPrestable() const override { return true; }
    void imprimir() const override {
        Material::imprimir();
        cout << " | Autor: " << autor << " | Paginas: " << paginas << endl;
    }
};

class Revista : public Material {
private:
    int numero;
    string editorial;

public:
    Revista(string c, string t, int a, int n, string e) : Material(c, t, a), numero(n), editorial(e) {}
    string getTipo() const override { return "Revista"; }
    bool esPrestable() const override { return numero < 50; }
    void imprimir() const override {
        Material::imprimir();
        cout << " | Numero: " << numero << " | Editorial: " << editorial << endl;
    }
};

class DVD : public Material {
private:
    int duracionMin;
    string clasificacion;

public:
    DVD(string c, string t, int a, int d, string cl) : Material(c, t, a), duracionMin(d), clasificacion(cl) {}
    string getTipo() const override { return "DVD"; }
    bool esPrestable() const override { return clasificacion != "18+"; }
    void imprimir() const override {
        Material::imprimir();
        cout << " | Duracion: " << duracionMin << " min | Clasificacion: " << clasificacion << endl;
    }
};

class Biblioteca {
private:
    Material* catalogo[100];
    int cantidad;

public:
    Biblioteca() : cantidad(0) {
        for (int i = 0; i < 100; i++) catalogo[i] = nullptr;
    }

    void agregar(Material* m) {
        if (m != nullptr && cantidad < 100) catalogo[cantidad++] = m;
    }

    void listarTodo() const {
        cout << "=== Catalogo completo ===" << endl;
        for (int i = 0; i < cantidad; i++) catalogo[i]->imprimir();
    }

    void listarPrestables() const {
        cout << "=== Materiales prestables ===" << endl;
        for (int i = 0; i < cantidad; i++) {
            if (catalogo[i]->esPrestable()) catalogo[i]->imprimir();
        }
    }

    void buscarPorTitulo(string titulo) const {
        cout << "=== Busqueda: " << titulo << " ===" << endl;
        bool encontrado = false;
        for (int i = 0; i < cantidad; i++) {
            if (catalogo[i]->getTitulo() == titulo) {
                catalogo[i]->imprimir();
                encontrado = true;
            }
        }
        if (!encontrado) cout << "No encontrado." << endl;
    }

    ~Biblioteca() {
        for (int i = 0; i < cantidad; i++) {
            delete catalogo[i];
            catalogo[i] = nullptr;
        }
    }
};

int main() {
    Biblioteca b;
    b.agregar(new Libro("L001", "El Principito", 1943, "Antoine de Saint-Exupery", 96));
    b.agregar(new Revista("R001", "Ciencia Hoy", 2022, 35, "USFQ Press"));
    b.agregar(new Revista("R002", "Archivo Historico", 1990, 80, "Municipal"));
    b.agregar(new DVD("D001", "Documental Galapagos", 2020, 90, "TP"));
    b.agregar(new DVD("D002", "Pelicula Adultos", 2018, 120, "18+"));

    b.listarTodo();
    b.listarPrestables();
    b.buscarPorTitulo("El Principito");

    return 0;
}
