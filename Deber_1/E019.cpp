#include <iostream>
using namespace std;

int main(){
	int n=0;
	cin>>n;
	for(int i=0;i<=n;i++){         //Si iniciamos i=1, se imprime a continuacion del numero, pero se ve mas bonito con ese espacio inicial :)
		for(int j=0;j<i;j++){
			cout<<"*";
		}
		cout<<endl;
	}
	
}
