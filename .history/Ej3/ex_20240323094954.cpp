#include <iostream>
#include "calculadora.h"
using namespace std;

void inicio(){
    bool bucle{true};
    while (bucle){
        Calculadora cal1();
        cout << "\x1B[31m" << "\n\n\tBienvenido, ingresa la operacion que quieres realizar: \n\t1. Suma\n\t2. Resta\n\t3. Multiplicación\n\t4. Inverso Multiplicativo" << "\x1B[m \n\t";
        int numero{0};
        cin >> numero;
        switch (numero){
        case 4:
            cal1.inverso_m();
            
            //cout << "\x1B[31m" << "\n\n\tSuma" << "\x1B[m \n\t";
            break;
        
        default:
            switch (numero){
            case 1:
                cal1.suma();
                break;
            case 2:
                cal1.resta();
                break;
            case 3:
                cal1.multi();
                break;
            default:
    
                break;
        }
            break;
        }
        cal1.print_res();
        
        
        int res;
        cout << "\n\n\tIngrese 1 para repetir" << "\n\t";
        cin >> res;
        if (res != 1) {
            bucle = false;
            break;
        }

    }
}


