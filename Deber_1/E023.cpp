#include <iostream>
using namespace std;
int main(){
	int N;
	int a=0;
	int b=1;
	int F=0;
	int suma=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cout<<a<<" ";
		F=a+b;
		a=b;
		b=F;
		
	}
	
}
