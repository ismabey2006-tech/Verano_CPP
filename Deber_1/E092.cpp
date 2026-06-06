#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Producto{
private:
    string nombre;
    double precio;

public:
    Producto(){
        nombre = "";
        precio = 0;
    }

    Producto(string n, double p){
        nombre = n;
        precio = p;
    }

    string getNombre(){
        return nombre;
    }

    double getPrecio(){
        return precio;
    }
};

int main(){
    int n;
    string nombre;
    double precio;

    cin >> n;

    Producto productos[100];

    for(int i = 0; i < n; i++){
        cin >> nombre >> precio;
        productos[i] = Producto(nombre, precio);
    }

    int caro = 0;
    int barato = 0;

    for(int i = 1; i < n; i++){
        if(productos[i].getPrecio() > productos[caro].getPrecio()){
            caro = i;
        }
        if(productos[i].getPrecio() < productos[barato].getPrecio()){
            barato = i;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Mas caro: " << productos[caro].getNombre() << " ($" << productos[caro].getPrecio() << ")" << endl;
    cout << "Mas barato: " << productos[barato].getNombre() << " ($" << productos[barato].getPrecio() << ")" << endl;

    return 0;
}
