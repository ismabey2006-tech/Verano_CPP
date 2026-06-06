#include <iostream>
#include <iomanip>
using namespace std;

double calcularIMC(double peso,double altura ){
	return peso/(altura*altura);
}
int main(){
	double peso, altura;
	cin>>peso>>altura;
	cout<<"IMC: "<<fixed<<setprecision(2)<<calcularIMC(peso,altura)<<endl;

}
