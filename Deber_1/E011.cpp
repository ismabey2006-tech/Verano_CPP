#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==0){
		cout<<"El numero es 0"<<endl;
	}
	else{
		if(n>0){
			cout<<"El numero es positivo"<<endl;
		}
		else
		cout<<"El numero es negativo"<<endl;
	}
	return 0;
}
