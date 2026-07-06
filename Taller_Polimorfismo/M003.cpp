#include <iostream>
#include <string>
using namespace std;

class Cancion {
public:
    string titulo;
    string artista;

    Cancion(string titulo, string artista)
        : titulo(titulo), artista(artista) {}
};

class Playlist {
private:
    Cancion** canciones;
    int capacidad;
    int cantidad;

    void expandir() {
        int nuevaCapacidad = capacidad * 2;
        Cancion** nuevo = new Cancion*[nuevaCapacidad];

        for (int i = 0; i < cantidad; ++i) {
            nuevo[i] = canciones[i]; // copia punteros, no objetos
        }

        delete[] canciones;
        canciones = nuevo;
        capacidad = nuevaCapacidad;

        cout << "Playlist expandida a " << capacidad << endl;
    }

public:
    Playlist(int capInicial)
        : canciones(new Cancion*[capInicial]), capacidad(capInicial), cantidad(0) {}

    ~Playlist() {
        for (int i = 0; i < cantidad; ++i) {
            delete canciones[i];
            canciones[i] = nullptr;
        }
        delete[] canciones;
        canciones = nullptr;
    }

    void agregar(string titulo, string artista) {
        if (cantidad == capacidad) {
            expandir();
        }
        canciones[cantidad] = new Cancion(titulo, artista);
        ++cantidad;
    }

    void imprimir() const {
        for (int i = 0; i < cantidad; ++i) {
            cout << (i + 1) << ". " << canciones[i]->titulo
                 << " - " << canciones[i]->artista << endl;
        }
    }
};

int main() {
    Playlist playlist(2);

    playlist.agregar("Bohemian Rhapsody", "Queen");
    playlist.agregar("Imagine", "John Lennon");
    playlist.agregar("Billie Jean", "Michael Jackson");
    playlist.agregar("Hotel California", "Eagles");
    playlist.agregar("Sweet Child O' Mine", "Guns N' Roses");

    playlist.imprimir();

    return 0;
}
