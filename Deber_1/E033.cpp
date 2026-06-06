#include <iostream>
#include <iomanip>
using namespace std;

double mayor(double a, double b){
    if(a > b){
        return a;
    }
    return b;
}

double mayor(double a, double b, double c){
    return mayor(mayor(a, b), c);
}

int main(){
    double a, b, c, d, e;

    cin >> a >> b;
    cin >> c >> d >> e;

    cout << fixed << setprecision(2);
    cout << "Mayor de 2: " << mayor(a, b) << endl;
    cout << "Mayor de 3: " << mayor(c, d, e) << endl;

    return 0;
}
