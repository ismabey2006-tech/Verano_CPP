#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n<0 || n>100){
	cout<<"Error, ingrese una nota valida"<<endl;}
	else{
	if(n<60){
		cout<<"Nota: "<<n<<" -> Calificacion: F"<<endl;
	}
	else{
		if(n<70){
		cout<<"Nota: "<<n<<" -> Calificacion: D"<<endl;
	}
	else{
		if(n<80){
		cout<<"Nota: "<<n<<" -> Calificacion: C"<<endl;
	}
	else{
		if(n<90){
		cout<<"Nota: "<<n<<" -> Calificacion: B"<<endl;
	}
	else{
		cout<<"Nota: "<<n<<" -> Calificacion: A"<<endl;
	}	
	}
	}
	}
	}
	
	
	
		return 0;
	}


