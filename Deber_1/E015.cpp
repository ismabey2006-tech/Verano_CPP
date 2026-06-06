#include <iostream>
using namespace std;

int main(){
	int N;
	int n;
	int suma=0;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>n;
		suma+=n;
	}
	cout<<"Suma total: "<<suma<<endl;
}
