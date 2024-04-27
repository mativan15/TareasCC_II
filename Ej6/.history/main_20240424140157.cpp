#include "header.h"
#include <iostream>
using namespace std;
int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }
int A[10]={0,1,2,3,4,5,6,7,8,9}; //
int B[10]={6,1,9,6,5,1,7,0,1,4}; //

int main(){
    int (*p)(int, int);
    int (*q)(int, int);
    p =&suma;// error
    cout << p << endl;
    cout << (*p)(5,6) << endl;//correcto = 11
    p = suma;
    cout << p(5,6) << endl;//correcto = 11

    int (*R[2])(int, int) = {suma, resta};
    int a{0};
    for (int i=0; i<10; i++){
        a = R[B[i]](a, A[i]);
        cout << a << " " << endl;
    }    
//cout << (*r)(A,B) << endl;
    //inicio();
    return 0;
}