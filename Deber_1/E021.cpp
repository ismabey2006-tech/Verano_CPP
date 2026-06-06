#include <iostream>
#include <string>
using namespace std;

int main(){
	string palabra;
	int vocales=0;
	
	cin>>palabra;
	for(int j=0;j<palabra.length();j++){
		if(palabra[j]=='a' ||palabra[j]=='e' ||palabra[j]=='i' ||palabra[j]=='o' ||palabra[j]=='u'||palabra[j]=='A' ||palabra[j]=='E' ||palabra[j]=='I' ||palabra[j]=='O' ||palabra[j]=='U'){
			vocales=vocales+1;
		}
	}
	cout<<"Vocales en \""<<palabra<<"\": "<<vocales<<endl;
}
