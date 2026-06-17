#include <iostream>
using namespace std;

int main() {
	
	int w=42; double x=3.14; char y='A'; bool z=true;
	
	int* p1=&w; double* p2=&x; char* p3=&y; bool* p4=&z;
	
	cout<<"int      : valor="<<w<<"    dir="<<p1<<"            *ptr="<<*p1<<endl;
	cout<<"double   : valor="<<x<<"  dir="<<p2<<"            *ptr="<<*p2<<endl;
	cout<<"char     : valor="<<y<<"     dir="<<p3<<"   *ptr="<<*p3<<endl;
	cout<<"bool     : valor="<<z<<"     dir="<<p4<<"            *ptr="<<*p4<<endl;
}
