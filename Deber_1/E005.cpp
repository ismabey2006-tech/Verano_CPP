#include <iostream>

using namespace std;

int main(){
	int a;
	int const b=2;
	cin>>a;
	if(a%b==0){
		cout<<a<<" % "<<b<<" = "<<a%b<<endl;
		cout<<"El numero es par"<<endl;
	}
	else{
	
	cout<<a<<" % "<<b<<" = "<<a%b<<endl;
		cout<<"El numero es impar"<<endl;
	}
	return 0;
}
