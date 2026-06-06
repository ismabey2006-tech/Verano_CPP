#include <iostream>
#include <iomanip>
using namespace std;

class Lista{
private:
    int* datos;
    int capacidad;
    int cantidad;

public:
    Lista(int c){
        capacidad = c;
        cantidad = 0;
        datos = new int[capacidad];
    }

    ~Lista(){
        delete[] datos;
        datos = nullptr;
        cout << "Destructor: memoria liberada." << endl;
    }

    void agregar(int val){
        if(cantidad < capacidad){
            datos[cantidad] = val;
            cantidad++;
        }
        else{
            cout << "Lista llena." << endl;
        }
    }

    void imprimir(){
        cout << "Lista: ";
        for(int i = 0; i < cantidad; i++){
            cout << datos[i] << " ";
        }
        cout << endl;
    }

    double promedio(){
        double suma = 0;
        for(int i = 0; i < cantidad; i++){
            suma += datos[i];
        }
        return suma / cantidad;
    }
};

int main(){
    int capacidad, valor;

    cin >> capacidad;

    cout << fixed << setprecision(2);

    Lista lista(capacidad);

    for(int i = 0; i < capacidad; i++){
        cin >> valor;
        lista.agregar(valor);
    }

    lista.imprimir();
    cout << "Promedio: " << lista.promedio() << endl;

    return 0;
}
