#include <iostream>
#include "calculadora.h"
#include "inverso.h"
using namespace std;
Calculadora::Calculadora(){
    num1 = 0;
    num2 = 0;
    mod = 0;
}
void Calculadora::inverso_m(){
    Inverso inv1(num1, mod);
}
void Calculadora::suma(){
    res = num1 + num2;
}
void Calculadora::multi(){
    res = num1 * num2;
}
void Calculadora::print_res(){
    res = res%mod;
    if (res < 0) {res = mod+res;}
    cout << "\x1B[96m" << "\n\tRespuesta: " << res << "\x1B[m" << endl;
}