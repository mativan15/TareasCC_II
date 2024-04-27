#include "header.h"
#include <iostream>
using namespace std;
int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }
int A[10]={0,1,2,3,4,5,6,7,8,9}; //
int B[10]={6,1,9,6,5,1,7,0,1}; //

int main(){
    int (*r[2])(int, int) ={suma, resta};
    int (*p)(int, int);
    int (*q)(int, int);
    p =&suma;// error
    cout << p << endl;
    cout << (*p)(5,6) << endl;//correcto = 11
    p = suma;
    cout << p(5,6) << endl;//correcto = 11
    cout << (*r)(A,B) << endl;//correcto = 11
    //inicio();
    return 0;
}