#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anio;
    double precio;

public:
    Libro(string titulo, string autor, int anio, double precio)
        : titulo(titulo), autor(autor), anio(anio), precio(0) {
        setPrecio(precio);
    }

    const string& getTitulo() const { return titulo; }
    const string& getAutor() const { return autor; }
    int getAnio() const { return anio; }
    double getPrecio() const { return precio; }

    void setPrecio(double p) {
        if (p >= 0) precio = p;
        else cout << "Precio invalido." << endl;
    }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Titulo: " << titulo << endl;
        cout << "Autor : " << autor << endl;
        cout << "Anio  : " << anio << endl;
        cout << "Precio: $" << precio << endl;
    }
};

int main() {
    Libro libro("El Principito", "Antoine de Saint-Exupery", 1943, 12.50);
    libro.imprimir();
    return 0;
}
