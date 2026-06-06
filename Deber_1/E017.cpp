#include <iostream>
using namespace std;

int main(){
	int N;int factorial=1;
	cin>>N;
	if(N>=0){
		for(int i=1;i<=N;i++){
			factorial=factorial*i;
			}
		cout<<N<<"! = "<<factorial<<endl;
	}
	else
	cout<<"Error, ingrese un valor no negativo"<<endl;
}


