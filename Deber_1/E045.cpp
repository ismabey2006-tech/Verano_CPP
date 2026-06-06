#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string nombres[100];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nombres[i];
    }

    for(int i = 0; i < n; i++){
        cout << i + 1 << ". " << nombres[i] << endl;
    }

    return 0;
}
