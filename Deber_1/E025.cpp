#include <iostream>
using namespace std;

int main(){
	int n;
	do{
		cout<<"Ingrese nota (0-100): "<<endl;
		cin>>n;
		if(n<0 ||n>100){
			cout<<"Valor invalido. Intente de nuevo."<<endl;
		}
	}while(n<0 ||n>100);
		cout<<"Nota aceptada: "<<n<<endl;
		}
