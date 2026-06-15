#include <iostream>
#include <string>
using namespace std;

class Recurso {
private:
    string nombre;

public:
    Recurso(string nombre) : nombre(nombre) {
        cout << nombre << " creado." << endl;
    }

    ~Recurso() {
        cout << nombre << " destruido." << endl;
    }
};

int main() {
    Recurso r1("A");
    {
        Recurso r2("B");
        {
            Recurso r3("C");
        }
    }
    return 0;
}
