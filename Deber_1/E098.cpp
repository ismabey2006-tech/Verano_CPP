#include <iostream>
#include <string>
using namespace std;

class Volador{
public:
    virtual void volar() = 0;
};

class Nadador{
public:
    virtual void nadar() = 0;
};

class Pato : public Volador, public Nadador{
private:
    string nombre;

public:
    Pato(string n){
        nombre = n;
    }

    void volar(){
        cout << nombre << " vuela: Fiu fiu!" << endl;
    }

    void nadar(){
        cout << nombre << " nada: Splash splash!" << endl;
    }
};

int main(){
    Pato pato("Donald");

    pato.volar();
    pato.nadar();

    return 0;
}
