#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double C;
	double F;
	cin>>C;
	F=C * (9.0/5.0 )+ 32;
	cout<<fixed<<setprecision(1)<<C<<" C = "<<fixed<<setprecision(1)<<F<<endl;
	return 0;
}
