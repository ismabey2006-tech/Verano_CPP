#include <iostream>
using namespace std;
int main(){
	int n;
	int positivos=0;
	int negativos=0;
	
	cin>>n;
	while(n!=0){
		if(n>0){
			positivos++;	
		}
		else{
		negativos++;}
		cin>>n;
	}
	cout<<"Positivos: "<<positivos<<endl;
	cout<<"Negativos: "<<negativos<<endl;
}
