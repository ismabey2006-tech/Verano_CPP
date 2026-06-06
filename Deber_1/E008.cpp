#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
	string n;
	int e;
	double est;
	cin>>n;
	cin>>e;
	cin>>est;
	cout<<"=== Ficha Personal ==="<<endl;
	cout<<left<<setw(8)<<"Nombre"<<": "<<n<<endl;
	cout<<left<<setw(8)<<"Edad"<<": "<<e<<" anos"<<endl;
	cout<<left<<setw(8)<<"Estatura"<<": "<<fixed<<setprecision(2)<<est<<" m"<<endl;
	return 0;
}
