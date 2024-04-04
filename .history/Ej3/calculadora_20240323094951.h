#include <iostream>
using namespace std;

class Calculadora {
public:
    int num1;
    int num2;
    bool resta;
    /*int centena;
    int millar;
    char simbolos[9];*/
    Calculadora();
    int inverso_m();
    int suma();
    int resta();
    int multi();
    void print_res();

};