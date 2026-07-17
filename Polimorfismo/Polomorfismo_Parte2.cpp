#include <iostream>
#include <string>
using namespace std;

class Jugador {
protected:
    string nombre;
    string pais;

public:
	Jugador(string nombre, string pais) : nombre(nombre), pais(pais) {}

    virtual string posicion() const = 0;
    virtual void actuar() = 0;
    virtual void imprimir() const {
        cout << "[" << pais << "] " << nombre << " - "
             << posicion() << endl;
    }

    virtual ~Jugador() {}
};

class Delantero : public Jugador{
	public:
    Delantero(string nombre, string pais) : Jugador(nombre, pais) {}

    string posicion() const override {
        return "Delantero";
    }

    void actuar() override {
        cout << nombre << " remata al arco!" << endl;
    }
	
};

class Portero : public Jugador{
	public:
		Portero(string nombre, string pais) : Jugador(nombre, pais) {}
		string posicion() const override {
        return "Portero";
    }

    void actuar() override {
        cout << nombre << " ataja el disparo!" << endl;
    }
};

class Mediocampista : public Jugador{
	public:
		Mediocampista(string nombre, string pais) : Jugador(nombre, pais) {}
		string posicion() const override {
        return "Mediocampista";
    }

    void actuar() override {
        cout << nombre << " da el pase clave!" << endl;
    }
};

int main(){
	Jugador* equipo[4];
	equipo[0]= new Portero("Buffon","Italia");
	equipo[1]= new Mediocampista("Iniesta","Espana");
	equipo[2]= new Delantero("CR7","Portugal");
	equipo[3]= new Delantero("Kitu Diaz","Argentina");
	
	for(int i=0;i<4;i++){
		equipo[i]->imprimir();
	}
	
	for(int i=0;i<4;i++){
		equipo[i]->actuar();
	}
	
	 for (int i = 0; i < 4; i++) {
        delete equipo[i];
        equipo[i] = NULL;
    }

    return 0;
	
	
}
