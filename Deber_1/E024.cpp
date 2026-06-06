#include <iostream>
using namespace std;
int main(){

int n;
do{
	cout<<"=== Menu ==="<<endl;
	cout<<"1. Saludar"<<endl;
	cout<<"2. Despedirse"<<endl;
	cout<<"3. Salir"<<endl;
	cin>>n;
	
	switch(n){
	
		case 1:
			cout<<"Hola!"<<endl;
			break;
		case 2:
			cout<<"Hasta luego!"<<endl;
			break;
		case 3:
			cout<<"Programa terminado"<<endl;
			break;
		default:
			cout<<"Ingrese una opcion valida"<<endl;
		}

}
while(n!=3);
}
