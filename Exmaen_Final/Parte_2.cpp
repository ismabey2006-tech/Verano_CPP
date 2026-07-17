#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Publicacion{
	protected:
		string titulo;
        string autor;
        int    anio;
    public:
    	Publicacion(string titulo, string autor, int anio): titulo(titulo), autor(autor), anio(anio) {}
    	
       virtual int diasPrestamo() const = 0;
       virtual void imprimir() const {
        cout << "[" << anio << "] " << titulo << " — " << autor << endl;
        cout << "Prestamo: " << diasPrestamo() << " dias" << endl;
    }
    
       string getTitulo() const {
        return titulo;
    }

    virtual ~Publicacion() {}


};


ostream& operator<<(ostream& os, const Publicacion& p) {
    p.imprimir();
    return os;
}

class Libro : public Publicacion {
private:
    int paginas;

public:
    Libro(string titulo, string autor, int anio, int paginas)
        : Publicacion(titulo, autor, anio), paginas(paginas) {}

    int diasPrestamo() const override {
        if (paginas <= 300) {
            return 14;
        } else {
            return 21;
        }
    }

    void imprimir() const override {
        Publicacion::imprimir();
        cout << "Paginas: " << paginas << endl;
    }
};

class Revista : public Publicacion {
private:
    int numero;

public:
    Revista(string titulo, string autor, int anio, int numero)
        : Publicacion(titulo, autor, anio), numero(numero) {}

    int diasPrestamo() const override {
        return 7;
    }

    void imprimir() const override {
        Publicacion::imprimir();
        cout << "Numero: " << numero << endl;
    }
};

int main() {
    Publicacion* publicaciones[4];

    publicaciones[0] = new Libro("Don Quijote", "Cervantes", 2021, 863);
    publicaciones[1] = new Revista("National Geographic", "Varios", 2023, 312);
    publicaciones[2] = new Libro("El Principito", "Nose", 2020, 120);
    publicaciones[3] = new Revista("Muy Interesante", "Varios", 2022, 45);

    for (int i = 0; i < 4; i++) {
        cout << *publicaciones[i] << endl;
    }

    ofstream archivo("catalogo.txt");

    if (!archivo) {
        cout << "Error al abrir catalogo.txt" << endl;
    } else {
        for (int i = 0; i < 4; i++) {
            archivo << publicaciones[i]->getTitulo()
                    << " - "
                    << publicaciones[i]->diasPrestamo()
                    << " dias"
                    << endl;
        }

        archivo.close();
    }

    for (int i = 0; i < 4; i++) {
        delete publicaciones[i];
        publicaciones[i] = nullptr;
    }

    return 0;
}
