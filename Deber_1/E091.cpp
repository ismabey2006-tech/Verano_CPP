#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Sensor{
private:
    string nombre;
    double valor;

public:
    Sensor(string n, double v){
        nombre = n;
        valor = v;
        cout << nombre << " activado." << endl;
    }

    ~Sensor(){
        cout << nombre << " desactivado." << endl;
    }

    double leer(){
        return valor;
    }

    string getNombre(){
        return nombre;
    }
};

int main(){
    cout << fixed << setprecision(2);

    Sensor s1("Temperatura", 36.6);
    Sensor s2("Presion", 101.3);

    cout << s1.getNombre() << ": " << s1.leer() << endl;
    cout << s2.getNombre() << ": " << s2.leer() << endl;

    return 0;
}
