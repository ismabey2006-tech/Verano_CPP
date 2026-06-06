#include <iostream>
using namespace std;

void intercambiar(int &a, int &b){
	cout<<"Antes: "<< "a="<<a<<", b="<<b<<endl;
	int s;
	s=a;
	a=b;
	b=s;
	cout<<"Despues: "<< "a="<<a<<", b="<<b<<endl;
}
int main(){
	int a, b;
	cin>>a;
	cin>>b;
	intercambiar(a,b);
}
