#include <iostream>
#include <string>
using namespace std;

void saludar(string nombre){
	cout<<"Hola, "<<nombre<<"! Bienvenido al sistema."<<endl;
};
int main(){
	string nombre;
	cin>>nombre;
	saludar(nombre);
	
}
