#include <iostream>
using namespace std;

int main(){
	int n;
	bool esPrimo=true;
	cin>>n;
	
	for(int i=2;i<n;i++){
		if(n%i==0){
		
		esPrimo=false;	}	
}
if(esPrimo==true){
	cout<<n<<" es primo"<<endl;
}
else
cout<<n<<" no es primo"<<endl;
		
	}

