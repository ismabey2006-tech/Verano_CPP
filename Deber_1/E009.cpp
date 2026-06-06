#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int a,b,c;
	
	cin>>a;
	cin>>b;
	cin>>c;
	double prom=(a+b+c)/3.0;
	cout<<"Promedio: "<<fixed<<setprecision(2)<<prom<<endl;
	return 0;
}
