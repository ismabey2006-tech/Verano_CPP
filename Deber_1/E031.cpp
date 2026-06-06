#include <iostream>
#include <iomanip>
using namespace std;

void calcularCirculo(double radio, double &area, double &per){
	double pi=3.14159;
	area=pi*radio*radio;
	per=2.0*pi*radio;
	
}
int main(){
	double radio,area,per;
	cin>>radio;
	calcularCirculo(radio,area,per);
	cout<<"Radio: "<<fixed<<setprecision(2)<<radio<<endl;
	cout<<"Area: "<<fixed<<setprecision(2)<<area<<endl;
	cout<<"Perimetro: "<<fixed<<setprecision(2)<<per<<endl;
}
