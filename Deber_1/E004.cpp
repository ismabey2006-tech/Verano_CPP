#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	double  a, b;
	cin>>a;
	cin>>b;
	cout<<"Total a pagar: "<<fixed<<setprecision(2)<<a*b<<endl;
	return 0;
}
