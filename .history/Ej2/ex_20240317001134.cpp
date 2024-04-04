#include <iostream>
#include "romanos.h"
using namespace std;

void iniciar(){
    bool bucle{true};
    while (bucle){
        cout << "\x1B[31m" << "\n\n\tBienvenido, ingresa un número del 1-9999: " << "\x1B[m \n\t";
        int numero{0};
        cin >> numero;
        Romanos rom1(numero);
        rom1.print_num();
        int res;
        cout << "\n\n\tIngrese 1 para repetir" << "\n\t";
        cin >> res;
        if (res != 1) {
            bucle = false;
            break;
        }

    }
}


