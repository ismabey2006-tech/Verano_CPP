#include <iostream>
#include <string>
using namespace std;

class Semaforo {
private:
    string estado;

public:
    Semaforo() : estado("rojo") {}

    void avanzar() {
        if (estado == "rojo") estado = "verde";
        else if (estado == "verde") estado = "amarillo";
        else estado = "rojo";
    }

    string getEstado() const { return estado; }

    void imprimir() const {
        cout << "Estado: " << estado << endl;
    }
};

int main() {
    Semaforo s;
    s.imprimir();
    for (int i = 0; i < 7; i++) {
        s.avanzar();
        s.imprimir();
    }
    return 0;
}
