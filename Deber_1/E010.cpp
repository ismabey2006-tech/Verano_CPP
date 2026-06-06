#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double pi = 3.14159;
	double radio=0.00;
	cin>>radio;
	cout<<"Radio: "<<fixed<<setprecision(2)<<radio<<endl;
	cout<<"Area: "<<fixed<<setprecision(2)<<pi*radio*radio<<endl;
	cout<<"Perimetro: "<<fixed<<setprecision(2)<<pi*radio*2<<endl;
	return 0;
}
