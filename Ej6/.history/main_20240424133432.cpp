#include "header.h"
int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }


int main(){
    int (*p)(int, int);
    p =&suma;
    cout << p << endl;
    inicio();
    return 0;
}