#include "header.h"
#include <iostream>
using namespace std;
int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }


int main(){
    int (*p)(int, int);
    int (*q)(int, int);
    p =&suma;
    cout << p << endl;
    cout << (*p)(5,6) << endl;
    p = suma;
    cout << p(5,6) << endl;
    inicio();
    return 0;
}