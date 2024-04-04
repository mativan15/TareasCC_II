#include <iostream>
#include "calculadora.h"
using namespace std;

void inicio(){
    bool bucle{true};
    while (bucle){
        Calculadora cal1;
        cout << "\x1B[31m" << "\n\n\tBienvenido, ingresa la operacion que quieres realizar: \n\t1. Suma\n\t2. Resta\n\t3. Multiplicación\n\t4. Inverso Multiplicativo" << "\x1B[m \n\t";
        int opcion{0};
        cin >> opcion;
        cout << "\n\n\tIngrese el primer operando:" << "\n\t";
        int n1{0};
        int n2{0};
        cin >> n1;
        switch (opcion){
        case 4:
            cal1.num1 = n1;
            cal1.inverso_m();
            break;
        default:
            cout << "\n\n\tIngrese el segundo operando:" << "\n\t";
            cin >> n2;
            cal1.num2 = n2;
            switch (opcion){
            case 1:
                cal1.suma();
                break;
            case 2:
                n2 = -n2;
                cal1.suma();
                break;
            default:
                cal1.multi();
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


